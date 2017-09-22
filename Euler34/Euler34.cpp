#include <cstdio>
#include <iostream>
#include "Header.h"

using namespace std;

void main() {
	long i = 10;
	int digits[] = { 9,0,0,0,0,0,0,0,0 };
	long long answer = 0;
	long long check = 0;
	int highestDig = 1;
	int k = 0;
	int overflow = 0;
	while (i < 10000000) {
		k = 0;
		check = 0;
		while (k < highestDig) {
			if (k == 0) {
				digits[k]++;
			}
			digits[k] += overflow;
			overflow = 0;
			if (digits[k] / 10 != 0) {
				digits[k] = digits[k] % 10;
				if (k == highestDig - 1) {
					highestDig++;
				}
				overflow = 1;
			}
			check += fact(digits[k]);
			k++;
		}
		if (check == i) {
			answer += check;
			printf("%I64d\n", check);
		}
		i++;
	}
	printf("The answer is %I64d", answer);
	cin.get();
}
long long fact(long num) {
	if (num <= 1) {
		return 1;
	}
	else {
		return fact((num - 1))*num;
	}
}