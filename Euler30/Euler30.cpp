#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

void main() {
	long answer = 0;
	long num = 2;
	long check = 0;
	long temp = 0;
	int i = 0;
	// probably want to deal with this as an array
	int digits[] = { 0,0,0,0,0,0 };
	while (num < 354294) {
		i = 0;
		check = 0;
		while (i < 6) {
			temp = powl(10,i);
			if (temp != 0) {
				temp = num / temp;
			}
			else {
				temp = num;
			}
			digits[i] = temp % 10;
			check += (powl(digits[i], 5));
			i++;
		}
		if (check == num) {
			answer += check;
		}
		num++;
	}
	printf("The answer is %d", answer);
	cin.get();
}