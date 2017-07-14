#include "Header.h"
#include <stdio.h>
#include <iostream>
;
using namespace std;
void e62(){
//generate cubes
//have is permutation function
// only need to check other cubes with same amount of digits
	long long int cubes[10000];
	for (long long int i=0;i<10000;i++){
		cubes[i]=(i)*(i)*(i);
	}
	long long int digits=1;
	for (int i=0;i<10000;i++){
		while(digits<cubes[i]){
			digits*=10;
		}
		int j=i+1;
		int counter=1;
		while (j<10000 && cubes[j]<digits){
			if (isPermutation(cubes[i],cubes[j])){
				counter++;
				if (counter==5){
					cout<<cubes[i]<<"\n";
					cout<<i<<"\n";
				}
			}
			j++;
		}
	}
	cin.get();
}

//assumes the 2 numbers have the same number of digits
bool isPermutation(long long int num1, long long int num2){
	long long int digits =1;
	int counter[10]={0};
	while (digits <= num1){
		counter[(num1/digits)%10]++;
		counter[(num2/digits)%10]--;
		digits*=10;
	}
	for (int i=0; i<10;i++){
		if (counter[i] != 0){
			return false;
		}
	}
	return true;
}