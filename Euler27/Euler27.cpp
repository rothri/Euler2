#include <cstdio>
#include <iostream>
#include "Header.h"

using namespace std;

void main() {
	long * primes = setPrimeArray(1000);
	long a = 0;
	long b = 3;
	long n = 0;
	int longestSequence = 0;
	long answer = 0;
	long num = 0;
	while (b < 1000) {
		if (IsPrime(&b,primes)) {
			a = -999;
			while (a < 1000) {
				n = 0;
				while (true) {
					num = n*n + a*n + b;
					if (num > 0) {
						if (IsPrime(&num, primes)) {
							if (n > longestSequence) {
								longestSequence = n;
								answer = a*b;
								printf("Answer %d is made of %d and %d with %d sequencelength \n",answer, a, b,n);
							}
						}
						else {
							break;
						}
					}
					else {
						break;
					}
					n++;
				}
				a++;
			}
		}
		b += 2;
	}
	printf("The answer is %d", answer);
	cin.get();
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