#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;

void main() {
	long long num = 1;
	long long count = 0;
	long long temp = 0;
	long long answer;
	while (num < 1000000) {
		temp = collatz(num);
		if (count < temp) {
			count = temp;
			answer = num;
			//printf("%I64d %I64d\n", count, answer);
		}
		num++;
	}
	printf("The answer is %I64d with the number %I64d", count, answer);
	cin.get();
}
long collatz(long long num) {
	long count = 0;
	while (num != 1) {
		if (num % 2 == 0) {
			num /= 2;
		}
		else {
			num = num * 3 + 1;
		}
		count++;
	}
	return count;
}