#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;
void main() {
	printf("%I64d",fact(40));
	cin.get();
}
long long nChooseK(long long n, long long k) {
	return (fact(n) / (fact(k)*fact(n - k)));
}
long long fact(long long num,int stop) {
	printf("%I64d\n", num);
	if (num == 1) {
		return 1;
	}
	else {
		return(fact(num - 1)*num);
	}
}