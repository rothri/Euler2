#include <cstdio>
#include <iostream>

using namespace std;

void main() {
	long long power = 0;
	long long num = 1;
	long long temp = num;
	long long answer = 0;
	long long mod = 10000000000;
	while (num <= 1000) {
		power = num;
		temp = num;
		while (power != 1) {
			temp *= num;
			if (temp > mod) {
				temp = temp%mod;
			}
			power--;
		}
		answer += temp;
		answer = answer%mod;
		num++;
	}
	printf("The answer is %I64d", answer);
	cin.get();
}