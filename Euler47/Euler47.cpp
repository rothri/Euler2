#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;

void main() {
	int n = 210;
	int temp = 0;
	long * primes = setPrimeArray(1000000);
	int factors[4] = { 0,0,0,0 };
	int count = 0;
	int i = 0;
	int k = 0;
	while (count != 4) {
		temp = n;
		i = 0;
		while (temp != 1) {
			if (temp%primes[i] == 0) {
				temp = temp / primes[i];
				k = 0;
				while (k < 4) {
					if (factors[k] == 0 ) {
						factors[k] = primes[i];
						break;
					}
					if (factors[k] == primes[i]) {
						break;
					}
					if (k == 3) {//means theres more than 4 primes
						factors[3] = 0;
						temp = 1; //so we skip this number and move on
					}
					k++;
				}
			}
			else {

				i++;
			}
		}
		k = 0;
		i = 1;
		while (k < 4) {
			if (factors[k] == 0) {
				i = 0;
			}
			factors[k] = 0;
			k++;
		}
		if (i != 0) {
			count++;
		}
		else {
			count = 0;
		}
		n++;
	}
	printf("The answer is:%d", n - 4);
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