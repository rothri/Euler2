#include <cstdio>
#include <iostream>
#include "Header.h"
#include <algorithm>
#include <cmath>;
#define panlength 7
using namespace std;

void main() {
	//just checking pandigitals starting with 9
	long* primes = setPrimeArray(10000);//hopefully this is enough, chance of false positive
	long pan = 987654321;
	long answer = 0;
	int i;
	// earlier runs showed there is no 9 digit pandgital prime
	int digits[] = { 1,2,3,4,5,6,7,8,9 };
	do {
		i = 0;
		pan = 0;
		while (i < panlength) {
			pan += digits[i]*pow(10, i);
			i++;
		}
		if (IsPrime(&pan, primes) && pan>answer) {
			answer = pan;
		}
	} 
	while (std::next_permutation(digits, digits + panlength));
	if (answer == 0) {
		printf("There are no pandigital primes of length %d", panlength);
	}
	else {
		printf("The answer is: %d", answer);
	}cin.get();
}
long * setPrimeArray(long length) {
	//length needs to be above 13
	long startPrimes[10000];
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