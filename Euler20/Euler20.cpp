#include <cstdio>
#include <iostream>

using namespace std;

void main() {
	int array2[310] = { 1 };
	int power = 0;
	int* pa;
	pa = array2;
	int i = 0;
	int num = 0;
	int overflow1 = 0;
	int overflow2 = 0;
	while (power<99)
	{
		power++;
		while (i < 305) {
			num = *pa;
			*pa = num * power;
			if (overflow1 > 0) {
				*pa = *pa + overflow1;
				overflow1 = 0;

			}
			overflow1 = overflow2;
			overflow2 = 0;
			if (*pa / 10 > 0) {
				if (*pa / 100 > 0) {
					overflow2 = *pa / 100;
				}
				overflow1 += (*pa % 100 - *pa % 10) / 10;
				*pa = *pa % 10;
			}
			i++;
			pa++;
		}

		pa = array2;
		i = 0;
	}
	long sum = 0;
	while (i < 310) {
		i++;
		sum += *pa;
		pa++;
	}
	printf("The answer %d", sum);
	cin.get();
}