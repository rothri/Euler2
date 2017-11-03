#include <cstdio>
#include <iostream>
#include "Header.h"
#include <algorithm>

using namespace std;

void main() {
	long * primes = setPrimeArray(10000);
	int i = 0;
	int prime[4] = { 0,0,0,0 };
	bool check = false;
	long num = 0;
	long lastNum = 0;
	long diff = 0;
	while (primes[i] != 0) {
		if (primes[i] > 1000) {
			check = false;
			prime[0] = primes[i] / 1000;
			prime[1] = (primes[i] % 1000) / 100;
			prime[2] = (primes[i] % 100) / 10;
			prime[3] = primes[i] % 10;
			lastNum = 10001;
			diff = 0;
			std::sort(prime, prime + 4);
			do {
				num = prime[3];
				num += prime[2] * 10;
				num += prime[1] * 100;
				num += prime[0] * 1000;
				if (IsPrime(&num, primes)) {
					if (lastNum < num) {
						if (diff == num-lastNum) {
							check = true;
						}
						diff = num - lastNum;
					}
					lastNum = num;
				}
			} while (std::next_permutation(prime, prime + 4));
		}
		if (check) {
			printf("This prime has prime permutations:%d\n", primes[i]);
		}
		i++;
	}
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