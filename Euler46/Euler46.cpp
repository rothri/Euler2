#include <cstdio>
#include <iostream>
#include "Header.h"

using namespace std;

void main() {
	long * primes = setPrimeArray(5000);
	long answer = 0;
	long number = 35;
	long square = 1;
	bool conjecture = true;
	while (conjecture) {
		if (!IsPrime(&number, primes)) {
			square = 1;
			while (2*square*square < number) {
				answer = number - 2*square*square;
				if (IsPrime(&answer, primes)) {
					break;
				}
				square++;
			}
			if (2*square*square > number) {
				answer = number;
				conjecture = false;
			}
		}
		number += 2;
	}
	printf("The answer is :%d", answer);
	cin.get();
}
long * setPrimeArray(long length) {
	//length needs to be above 13
	//returns all primes below length
	long startPrimes[5000];
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