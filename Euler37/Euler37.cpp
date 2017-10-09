#include <iostream>
#include <cstdio>
#include "Header.h"

using namespace std;
void main() {
	long *primes = setPrimeArray(800000);
	long *primes2 = primes;
	int count = 0;
	long left = 0;
	long right = 0;
	long answer = 0;
	int k = 10;
	while (*primes <8){
		primes++;
	}
	while (count < 11) {
		int i = 1;
		while (i < *primes) {
			i *= 10;
		}
		i /= 10;
		k = 10;
		while (i != 1) {
			right = *primes / k;
			k *= 10;
			left = *primes%i;
			if (!( IsPrime(&left, primes2) &&IsPrime(&right,primes2))) {
				break;
			}
			i /= 10;
			if (i == 1) {
				printf("Prime:%d\n", *primes);
				answer += *primes;
				count++;
			}
		}
		primes++;
		if (*primes == 0) {
			break;
		}
		//if (*primes == 3797) {
		//	k=10;
		//}
		//printf("Prime:%d\n", *primes);
	}
	printf("The answer is %d", answer);
	cin.get();
}
long * setPrimeArray(long length) {
	//length needs to be above 13
	//returns all primes below length
	long startPrimes[800000];
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
	if (*num == 1) {
		return false;
	}
	if (*num == 5) {
		return true;
	}
	if (*num == 2 || *num ==3) {
		return true;
	}
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