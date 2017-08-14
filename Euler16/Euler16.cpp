#include <cstdio>
#include <iostream>

using namespace std;

void main() {
	int array2[310] = { 1 };
	int power = 0;
	int* pa;
	pa=array2;
	int i =0;
	int num = 0;
	int overflow = 0;
	while (power<1000)
	{
		power++;
		while (i < 305) {
			num = *pa;
			*pa = num*2;
			if (overflow > 0) {
				*pa = *pa + 1;
				overflow = 0;
				
			}
			if (*pa/10 > 0) {
				*pa = *pa % 10;
				overflow++;
			}
			i++;
			pa++;
		}

		pa = array2;
		i = 0;
	}
	long sum =0;
	while (i < 310) {
		i++;
		sum += *pa;
		pa++;
	}
	printf("The answer %d", sum);
	cin.get();
}