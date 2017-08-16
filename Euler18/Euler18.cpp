#include <cstdio>
#include <iostream>
using namespace std;
void main() {
	int x = 365 % 7; //Jan1 1901 starting from monday so 6=sunday
	int year = 1;
	int count = 0;
	while (year < 101) {
		if (x == 6) {
			count += 1;
		}
		x += 31;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		if (year % 4 == 0) {
			x += 29;
		}
		else {
			x += 28;
		}
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 31;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 30;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 31;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 30;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 31;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 31;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 30;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 31;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 30;
		x = x % 7;
		if (x == 6) {
			count += 1;
		}
		x += 31;
		x = x % 7;
		year++;
	}
	printf("The answer is %d", count);
	cin.get();
}