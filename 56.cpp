#include <iostream>
#include "Header.h"
;
void e56(){
	int a=1;
	int b=1;
	int i=0;
	long long int biggest=0;
	long long int sum=0;
	int currentNum[400];
	int currentDigit=0;
	while(a<100){
		b=1;
		while(b<100){
			i=0;
			std::fill( currentNum, currentNum+400, -1 );
			currentNum[0]=a%10;
			currentNum[1]=a/10;//since a is less than 100
			if(currentNum[1]==0){
				currentNum[1]=-1;
			}
			while(i<b){
				currentDigit=intArrMult(currentNum,a);
				sum=digitSum(currentNum);
				if(sum >= biggest){
					biggest=sum;
					std::cout<<"A is "<<a;
					std::cout<<" B is "<<b;
					std::cout<<" The sum is "<<biggest<<"\n";
				}
				i++;
			}
			b++;
		}
		a++;
	}
	std::cin.get();
}
int intArrMult(int* arrNum, int num){
	/* Takes an array of a large number terminating in negative 1
	and a number to multiply the array by. Returns the greatest digit of the array
	and modifies the passed array to be the product.*/
	int i=0;
	while(true){
		if(arrNum[i]==-1){
			break;
		}
		i++;
	}
	int lastDigit=i-1;
	i=0;
	int remainder=0;
	while(i<=lastDigit){
		arrNum[i]*=num;
		if(remainder>0){
			arrNum[i]+= remainder;
			remainder=0;
		}
		if(arrNum[i]>9){
			remainder=arrNum[i]/10;
			arrNum[i]=arrNum[i]%10;
		}
		i++;
		if(remainder>0 && arrNum[i]==-1){
			arrNum[i]=0;
			lastDigit++;
		}
	}
	return lastDigit;
}
long long int digitSum(int* arrNum){
	int i=0;
	long long int sum =0;
	while(true){
		if(arrNum[i]==-1){
			return sum;
		}
		sum+= arrNum[i];
		i++;
	}
}