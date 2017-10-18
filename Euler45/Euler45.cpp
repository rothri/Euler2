#include <cstdio>
#include <iostream>

using namespace std;

void main() {
	long long n = 286;
	long long tnum = 0;
	long long pnum = 0;
	long long hnum = 0;
	long long min = 0;
	long long max = 286;
	long long guess;
	bool answer = false;
	while (n < 50000000) {
		tnum = (n*n + n) / 2;
		pnum = 0;
		hnum = 0;
		guess = n / 2;
		max = n;
		min = 143;
		while (pnum != tnum) {
			pnum = (guess*guess * 3 - guess) / 2;
			if (pnum > tnum) {
				max = guess;
			}
			else {
				min = guess;
			}
			if (guess == (max - min) / 2 + min) {
				break;
			}
			guess = (max - min) / 2 + min;
		}
		if (pnum == tnum) {
			guess = n / 2;
			max = n;
			min = 143;
			while (hnum != tnum) {
				hnum = (guess*guess * 2 - guess);
				if (hnum == tnum) {
					printf("Answer found: %d\n", tnum);
					answer = true;
					break;
				}
				if (hnum > tnum) {
					max = guess;
				}
				else {
					min = guess;
				}
				if (guess == (max - min) / 2 + min) {
					break;
				}
				guess = (max - min) / 2 + min;
			}
		}
		if (answer) {
			break;
		}
		n++;
	}
	printf("Done!");
	cin.get();
}