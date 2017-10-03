#include <cstdio>
#include <iostream>
#include "Header.h"
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;

void main() {
	long* primes = setPrimeArray(1000);
	long digits[] = { 1,0,1,0,0,0 };
	long i = 101;
	bool check = true;
	long k = 0;
	int x = 0;
	int dig = 3;
	long circle = 0;
	int answer = 13; //13 circular primes below 100
	while (1000000>i) {
		if (check && IsPrime(&i, primes)) {
			int* temp = new int[dig ];
			x = 0;
			while (x<dig && check) {
				x++;
				circle = 0;
				k = 0;
				while (k < dig) {
					temp[k] = digits[(k+x)%dig];
					k++;
				}
				k = 0;
				while (k < dig) {
					circle += temp[k] * pow(10, k);
						k++;
				}
				if (!IsPrime(&circle, primes)) {
					check = false;
				}

			}
			if (check) {
				answer++;
			}
			delete [] temp;
		}
		check = true;
		i += 2;
		if (i / long(pow(10, dig)) != 0) {
			dig++;
		}
		k = 0;
		while (k < dig) {
			digits[k] = (i / long(pow(10, k))) % 10;
			if (digits[k] % 2 == 0) {
				check = false;
			}
			k++;
		}
	}
	printf("The answer is %d", answer);
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