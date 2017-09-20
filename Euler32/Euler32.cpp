#include <cstdio>
#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;
void main() {
	int num = 0;
	int count = 0;
	int last[1000];
	long answer = 0;
	bool check = true;
	int i = 0;
	bool digitArray[] = { true,true,true,true,true,true,true,true,true };
	int a = 10;
	int b = 100;
	while (a < 100) {
		if (getPlace(a, 1) == 0) {
			a++;
		}
		if (getPlace(a, 1) == getPlace(a, 2)) {
			a++;
			if (a == 100) {
				break;
			}
		}
		b = 123;
		while (b < 1000) {
			digitArray[getPlace(a, 1) - 1] = false;
			digitArray[getPlace(a, 2) - 1] = false;
			i = 1;
			check = true;
			while (i < 4) {
				if (getPlace(b, i) == 0) {
					check = false;
					break;
				}
				if (!digitArray[getPlace(b, i) - 1]) {
					check = false;
					break;
				}
				if (i == 1) {
					if (getPlace(b, 1) == getPlace(b, 2) || getPlace(b, 1) == getPlace(b, 3)) {
						check = false;
						break;
					}
					if (getPlace(b, 2) == getPlace(b, 3)) {
						check = false;
						break;
					}
				}
				i++;
			}
			if (check) {
				digitArray[getPlace(b, 1) - 1] = false;
				digitArray[getPlace(b, 2) - 1] = false;
				digitArray[getPlace(b, 3) - 1] = false;
				num = a*b;
				if (num > 9999) {
					check = false;
				}
				i = 1;
				while (i < 5) {
					if (getPlace(num, i) == 0) {
						check = false;
						break;
					}
					if (digitArray[getPlace(num, i) - 1]) {
						digitArray[getPlace(num, i) - 1] = false;
					}
					else {
						check = false;
						break;
					}
					i++;
				}
				if (check) {
					i = 0;
					while (i < count) {
						if (last[i] == num) {
							answer -= num;
							break;
						}
						i++;
					}
					last[count] = num;
					count++;
					answer += num;
					printf("%d is made of %d and %d\n", num, a, b);
				}
				i = 0;
				while (i < 9) {
					digitArray[i] = true;
					i++;
				}
			}
			b++;
		}
		i = 0;
		while (i < 9) {
			digitArray[i] = true;
			i++;
		}
		a++;
	}
	a = 1;
	b = 1000;
	while (a < 10) {
		b = 1000;
		while (b < 10000) {
			digitArray[a - 1] = false;
			check = true;
			i = 1;
			while (i < 5) {
				if (getPlace(b, i) == 0) {
					check = false;
					break;
				}
				if (!digitArray[getPlace(b, i) - 1]) {
					check = false;
					break;
				}
				if (i == 1) {
					if (getPlace(b, 1) == getPlace(b, 2) || getPlace(b, 1) == getPlace(b, 3)) {
						check = false;
						break;
					}
					if (getPlace(b, 2) == getPlace(b, 3) || getPlace(b, 2) == getPlace(b, 4)) {
						check = false;
						break;
					}
					if (getPlace(b, 4) == getPlace(b, 1) || getPlace(b, 4) == getPlace(b, 3)) {
						check = false;
						break;
					}
				}
				i++;
			}
			if (check) {
				digitArray[getPlace(b, 1) - 1] = false;
				digitArray[getPlace(b, 2) - 1] = false;
				digitArray[getPlace(b, 3) - 1] = false;
				digitArray[getPlace(b, 4) - 1] = false;
				num = a*b;
				i = 1;
				while (i < 5) {
					if (getPlace(num, i) == 0) {
						check = false;
						break;
					}
					if (digitArray[getPlace(num, i) - 1]) {
						digitArray[getPlace(num, i) - 1] = false;
					}
					else {
						check = false;
						break;
					}
					i++;
				}
				if (num > 9999) {
					check = false;
				}
				if (check) {
					i = 0;
					while (i < count) {
						if (last[i] == num) {
							answer -= num;
							break;
						}
						i++;
					}
					last[count] = num;
					count++;
					printf("%d is made of %d and %d\n", num,a,b);
					answer += num;
				}
				i = 0;
				while (i < 9) {
					digitArray[i] = true;
					i++;
				}
			}
			b++;
		}
		digitArray[a - 1] = true;
		a++;
	}
	printf("The answer is %d",answer);
	cin.get();
}
int getPlace(long long num, int digit) {
	long tens = powl(10, digit-1);
	int answer = 0;
	num = num / tens;
	answer = num % 10;
	return answer;
}