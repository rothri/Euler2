#include <iostream>
#include "Header.h"
int main (){
	int ans =0;
	int n=23;
	int r=1;
	int nMinusR=0;
	while (n<=100){
		r=1;
		while(r<n){
			if (nchooser(n,r)){
				//nchooser == nchoose(n-r)
				nMinusR=n-r;
				ans+=(nMinusR-r) +1;
				r=n;
			}
			r++;
		}
		n++;
	}
	std::cout<<ans<<std::endl;
	std::cin.get();
	return ans;
};
bool nchooser (int n, int r){
	const long int max= 1000000;
// Takes n and r and returns true if the value will be over 1 million
	if (r>n){
		return false;
	}
	//optimizing to avoid overflows	

	int numBottom = r;
	int denomTop =n-r;
	if( denomTop >= numBottom+1){
		numBottom=denomTop;
		denomTop=r;
		if(numBottom+1 ==denomTop){
			numBottom++;
			denomTop--;
		}
	}
	long long int numerator = factorial(n,numBottom);
	if (numerator<0){//now we have to estimate in a different manner since the number is too big
		long long int multiple =1;
		const int maxlength=99;//we wont be dealing with anything past 99
		int numerators[maxlength]={};
		int denominators[maxlength]={};
		populateArray(numerators,n,numBottom);
		populateArray(denominators,denomTop,1);
		int k =denomTop;
		int i=0;//address to iterate over denominators
		int j=0;//address to iterate over numerators
		while (k*2 > numBottom){
			if(k*2 <= n){
				multiple*=2;
				denominators[i]=1;
				if(numerators[j]!= k*2){
					j=0;
					while(numerators[j]!=0){
						if(numerators[j]==k*2){
							numerators[j]=1;
							break;
						}
						j++;
					}
				}
				else{
					numerators[j]=1;
				}
				j+=2;
			}
			i++;
			k--;
		}
		if(multiple>max){
			return true;
		}
		if(multiple<0){
			return true;
		}
		else{
			int i=0;
			while(multiple>1 || denominators[i]!=0){
				if (denominators[i]%2==0){
					denominators[i]/=2;
					multiple/=2;
				}
				else{
					i++;
				}
			}
		}
		numerator= calcArray(numerators);
		if (numerator<0){
			return false; 
		}
		long long int denominator =calcArray(denominators);
		if (denominator<0){
			return false;
		}
		long long int temp= numerator/denominator;
		temp*=multiple;
		if (temp>max){
			return true;
		}
		else{
			return false;
		}
	}
	 if (numerator <max){
		return false;
	}
	 long long int denominator = factorial(denomTop,1);
	if (denominator<0){//overflow
		return false;
	}
	if (numerator/denominator>max){
		return true;
	}
	else{
		return false;
	}
};
long long int factorial (int n, int r){
	//assumes were trying to find n!/r! to find n! set r as 1
	if (n ==r){
		return 1;
	}
	else{
		return factorial(n-1,r)*n;
	}
};
void populateArray(int * arr , int n, int r){
	//populates an array with n,n-1.....r+1 then returns
	int i=0;
	while(n > r){
		arr[i]=n;
		n--;
		i++;
	}
	return ;
};
long long int calcArray(int * arr){
	int i =0;
	long long int answer=1;
	while(arr[i]!=0){
		answer*= arr[i];
		i++;
	}
	return answer;
}