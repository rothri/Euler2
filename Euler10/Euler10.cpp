#include <cstdio>
#include "Header.h"
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char ** argv)
{
	long long lastPrime = 0;
	long long primeArray[100000] = { 2,3,5,7,11,13,17,19 };
	long long num = 21;
	long long sum = 77;
	long long count = 8;
	long long* pa = &primeArray[7];
	while (count < 100001)
	{
		if (IsPrime(&num, primeArray)) {
			if (lastPrime < 1000000) {
				pa++;
				*pa = num;
				sum += num;
				lastPrime = num;
				count += 1;
			}
			else {
				sum += num;
			}
		}
		num += 2;
		if (num > 2000000) {
			printf("The Answer is %I64d\n", sum);
			break;
		}
	}
	printf("%I64d\n", lastPrime);
	//printf("The 100,001st prime is %I64d\n", primeArray[100000]);
	//num = 1;
	//for (int i : primeArray) {
	//	if (i == 0) {
	//		break;
	//	}
	//	printf("%d is the %d prime\n", i,num);
	//	num++;
	//}
	cin.get();
	return 0;
}
bool IsPrime(long long* num, long long*primeArray) {
	long sqNum = ceil(sqrt(*num));
	while (*primeArray != 0) {
		if (*num % *primeArray == 0) {
			return false;
		}
		if (sqNum < *primeArray) {
			return true;
		}
		primeArray++;
	}
	return true;
}