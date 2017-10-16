#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

void main() {
	long long answer = 0;
	long long last = 0;
	long long temp = 0;
	int i = 1;
	int pan[] = { 0,1,2,3,4,5,6,7,8,9 };
	int primes[] = { 2,3,5,7,11,13,17 };
	do {
		if (pan[0] != 0) {
			i = 1;
			while (i < 8) {
				temp = 100 * pan[i] + 10 * pan[i + 1] + pan[i + 2];
				if (temp % primes[i-1] != 0) {
					break;
				}
				i++;
			}
			if (i == 8) {
				i = 10;
				temp = 1;
				while (i > 0) {
					i--;
					answer += pan[i] * temp;
					// fun fact the computer evaluates temp*pan[i] as an int not a long cause lots of problems.
					if (i != 0) {
						temp *= 10;
					}
				}
				last = answer - last;
				printf("%I64d\n", last);
				last = answer;
			}
		}
	} while (std::next_permutation(pan, pan + 10));
	printf("The answer is:%I64d", answer);
	cin.get();
}