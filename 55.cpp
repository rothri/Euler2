#include <iostream>
#include "Header.h"
using namespace std;

void e55() {
	//this code is very gross and ineffecient please ignore :(
	int answer=0;
	int currentNum[400];
	std::fill( currentNum, currentNum+400, -1 );
	currentNum[0]=0;
	int temp[1]={1};
	int largestDigit=0;
	for(int i=1;i<10000;i++){
		largestDigit=intArrAdd(currentNum,temp);//add 1
		if(currentNum[largestDigit+1]>=0){
			largestDigit++;
		}
		int array1[400];
		memcpy(array1,currentNum,400);
		int yarra[400];
		for(int j=0; j<=48;j++)
		{

			memcpy(yarra,array1,400);
			reverseNumArr(yarra,array1,largestDigit);
			largestDigit=intArrAdd(array1,yarra);
			if(isNumArrPalindrome(array1,largestDigit)){
				break;
			}
			if (j==48){
				answer++;
			}

		}
	}
	cout<<answer<<"\n";
	cin.get();
	return;
}
bool isNumArrPalindrome(int* numArr,int lastDigit=-1){
	/*takes an array filled with -1 and digits of an integer starting at [0] and returns true if it is a palindrome
	*/
	if (numArr[0]<0){
		return false;
	}
	int i=0;
	if (lastDigit==-1){
	int lastDigit=0;
	while(true){
		if(numArr[i]<0){
			lastDigit=i-1;
			break;
		}
		i++;
	}
	}
	i=0;
	while(i<lastDigit){
		if(numArr[i]!=numArr[lastDigit]){
			return false;
		}
		i++;
		lastDigit--;
	}
	return true;
}
int intArrAdd(int* arr1,int* arr2){
	//returns arr1 +arr2 where arr1 was. Does not modify arr2 also returns the largest digit of arr1
	int lastdigit1=0;
	int lastdigit2=0;
	while(arr1[lastdigit1]>=0 || arr2[lastdigit2]>=0){
		if(arr1[lastdigit1]>=0){
			lastdigit1++;
		}
		if(arr2[lastdigit2]>=0){
			lastdigit2++;
		}
	}
	lastdigit1--;
	lastdigit2--;
	int i=0;
	while(i<=lastdigit1 || i<=lastdigit2){
		if(i<=lastdigit2){
		if(arr1[i]<0){
			arr1[i]=0;
			lastdigit1++;
		}
			arr1[i]+=arr2[i];
		}
		if(arr1[i]>=10){
			arr1[i]= arr1[i]%10;
			if(i==lastdigit1){
				lastdigit1++;
				arr1[i+1]=1;
			}
			else{
				arr1[i+1]++;
			}
		}
		i++;
	}
	return lastdigit1;
}
void reverseNumArr(int* arr1,int*arr2, int lastDigit=-1){
	//sends the content of arr2 to arr1 in reverse order
	int i=0;
	if (lastDigit==-1){
		int lastDigit=0;
		while(true){
			if(arr2[i]<0){
				lastDigit=i-1;
				break;
			}
			i++;
		}
		i=0;
	}
	while(lastDigit>=0){
		arr1[i]=arr2[lastDigit];
		i++;
		lastDigit--;
	}
	return;
}