#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void main() {
	// Lets make the most ineffecient way to answer this problem
	// this problem is easy except for the numbers 2 and 3
	int sub = 2;
	int j = 0;
	int power = 0;
	int count = 0;
	int factors[] = { 1,2, 3, 4, 5, 6 ,0 };//2 4 8 16 32 64
	int donePowers[500];
	donePowers[0] = 0;
	int i = 2;
	int k = 0;
	long answer = 0;
	answer = 99 * 99;
	answer = answer - 49 * 4;//5,6,7,10
	while (factors[j] != 0) {
		i = 2;
		power = factors[j];
		if (power == 5) {
			sub = 1;
		}
		if (power == 6) {
			printf("%d\n", count);
		}
		count = 0;
		while (i < 101) {
			k = 0;
			power *=i;
			while (k < 500) {
				if (donePowers[k] == 0) {
					donePowers[k] = power;
					donePowers[k + 1] = 0;
					break;
				}
				if (donePowers[k] == power) {
					printf("%d\n",power);
					answer = answer - sub;
					count += 1;
					break;
				}
				k++;
			}
			power /= i;
			i++;
		}
		j++;
	}
	printf("The answer is %d\n", answer);
	cin.get();
}
