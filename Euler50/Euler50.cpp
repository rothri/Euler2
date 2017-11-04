#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;

void main() {
	long * primes = setPrimeArray(100000);
	long  primeSum = 0;
	int count = 0;
	int i = 0;
	int min = 0;
	int max = 1000;
	bool check = true;
	while (max > 100) {
		if (!check) {
			break;
		}
		count = 0;
		primeSum = 0;
		min = 0;
		i = 0;
		while (primes[i] < 10000) {
			count++;
			primeSum += primes[i];
			if (count > max) {
				count = max;
				primeSum -= primes[min];
				min++;
				if (IsPrime(&primeSum, primes)) {
					printf("This prime %d can be written as a sum of %d primes\n", primeSum, max);
					check = false;
					break;
				}
			}
			if (primeSum > 1000000) {
				//prime sum is too big, so stop going up
				break;
			}
			i++;
		}
		max--;
	}
	cin.get();
}
long * setPrimeArray(long length) {
	//length needs to be above 13
	//returns all primes below length
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