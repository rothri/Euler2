#include "Header.h"
#include <iostream>
using namespace std;
void e60(){//takes a few minutes, could optimize it a bit more
	const int length= 1000000;
	long *primeArray=setPrimeArray(length);
	long sum=100000000;
	long primes[5]={0,1,2,3,4};
	long num=0;
	bool goodSet=false;
	while(primes[4]<10000){
		while(primes[0]<primes[1]){//this could probably be done in a more abstract way with 2 for loops
			primes[1]=primes[0]+1;
			while(primes[1]<primes[2]){
				primes[2]=primes[1]+1;
				while(primes[2]<primes[3]){
					primes[3]=primes[2]+1;
					while(primes[3]<primes[4]){
						goodSet=true;
						for(int i=1;i<5;i++){
							for(int j=0;j<i;j++){
								if(!isWorkingSet(primes[i],primes[j],primeArray)){
									goodSet=false;
									break;
								}
							}
							if(!goodSet){
								break;
							}
						}
						if(goodSet){
							num=0;
							for(int i=0;i<5;i++){
								num+=primeArray[primes[i]];
							}
							if(num<sum){
								cout<<"found possible answer "<<num<<"\n";
								sum=num;
							}
						}
						primes[3]++;
					}
					primes[2]++;
					while(!isWorkingSet(primes[1],primes[2],primeArray) || !isWorkingSet(primes[0],primes[2],primeArray)){
						if(primes[2]==primes[3]){
							break;
						}
						primes[2]++;
					}
				}
				primes[1]++;
				while(!isWorkingSet(primes[0],primes[1],primeArray) || !isWorkingSet(primes[1],primes[4],primeArray)){
					if(primes[1]==primes[2]){
						break;
					}
					primes[1]++;
				}
			}
			primes[0]++;
			while(!isWorkingSet(primes[0],primes[4],primeArray)){
					if(primes[1]==primes[2]){
						break;
					}
					primes[0]++;
				}
		}
		primes[0]=0;
		primes[1]=1;
		primes[2]=2;
		primes[3]=3;
		primes[4]++;
}
	cin.get();
}
long concactNumber(long num1, long num2){
	//returns num1num2 in long form
	long powten=10;
	while(true){
		if(num2/powten==0){
			break;
		}
		else{
			powten*=10;
		}
	}
	long answer=num1*powten+num2;
	return answer;
}
bool isWorkingSet(long num1, long num2,long*primeArray){
	long check=concactNumber(primeArray[num1],primeArray[num2]);
	long check2=concactNumber(primeArray[num2],primeArray[num1]);
	if(!IsPrime(&check,primeArray) || !IsPrime(&check2,primeArray)){
		return false;
	}
	return true;
}