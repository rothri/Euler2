#include "Header.h"
#include <iostream>
using namespace std;
void main (){
	const int length= 600000;
	long *primeArray=setPrimeArray(length);
	long diag1[length/10]={0};
	long diag2[length/10]={0};
	long rowLength=3;
	int i=2;
	long rowNum=10;
	int primes=3;
	int nonPrimes=1;
	while(i<length/10){
		rowNum+=rowLength;
		diag1[i]=rowNum;
		rowLength++;
		rowNum+=rowLength;
		diag2[i]=rowNum;
		rowNum+=rowLength;
		diag1[i+1]=rowNum;
		rowLength++;
		rowNum+=rowLength;
		diag2[i+1]=rowNum-1;
		if(IsPrime(&diag1[i],primeArray)){
			primes++;
		}else{
			nonPrimes++;
		}
		if(IsPrime(&diag1[i+1],primeArray)){
			primes++;
		}else{
			nonPrimes++;
		}
		if(IsPrime(&diag2[i],primeArray)){
			primes++;
		}else{
			nonPrimes++;
		}
		if(IsPrime(&diag2[i+1],primeArray)){
			primes++;
		}else{
			nonPrimes++;
		}
		if(primes*10<(nonPrimes+primes)){
			rowLength-=2;//ignore the last square
			cout<<rowLength;
			break;
		}
		i+=2;
	}
	cin.get();
}
long * setPrimeArray(long length) {
	//length needs to be above 13
	//returns all primes below length
	long startPrimes[90000];
	startPrimes[0] = 2;
	startPrimes[1] = 3;
	startPrimes[2] = 5;
	startPrimes[3] = 7;
	startPrimes[4] = 11;
	long i = 5;
	long n = 13;
	while (n < length) {
		if (IsPrime(&n, startPrimes)) {
			startPrimes[i] = n;
			i++;
		}
		n = n + 2;
	}
	long * primes = new long[i + 1];
	n = 0;
	while (n < i) {
		primes[n] = startPrimes[n];
		n++;
	}
	primes[i] = 0;
	return primes;
}
bool IsPrime(long* num, long*primeArray) {
	long sqNum = ceil(sqrt(*num));
	while (*primeArray != 0) {
		if (*num % *primeArray == 0) {
			return false;
		}
		if (sqNum < *primeArray) {
			return true;
		}
		primeArray++;
	}
	return true;
}