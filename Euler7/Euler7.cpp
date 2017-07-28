
#include <cstdio>
#include "Header.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	long long primeArray[10000] = { 2,3,5,7,11,13,17,19 };
	long long num = 21;
	int count = 8;
	long long* pa = &primeArray[7];
	while (count < 10001)
	{
		if (IsPrime(num, primeArray)) {
			pa++;
			*pa = num;
			count += 1;
		}
		num+=2;
	}
	printf("%I64d\n", num);
	printf("The 10,001st prime is %I64d\n", primeArray[10000]);
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
bool IsPrime(long long num,long long*primeArray) {
	while (*primeArray != 0) {
		if (num % *primeArray == 0) {
			return false;
		}
		primeArray++;
	}
	return true;
}