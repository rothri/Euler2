#include <cstdio>
#include <iostream>
using namespace std;

void main() {
	//a =m^2 - n^2
	//b = 2mn
	//c = m^2 + n^2
	// a + b +c = 1000
	// 2m^2 +2mn = 1000;
	// m^2 +mn =500
	int m = 1;
	int n = 2;
	while (m < 30) {
		while (((m*m)+(m*n)) <= 500)
		{
			if ((m*m + m*n) == 500) {
				printf("m is %d, n is %d\n", m, n);
				printf("Which means a is %d, b is %d, and c is %d\n", (m*m) - (n*n), 2 * m*n, (m*m) + (n*n));
				break;
			}
			n++;
		}
		n = 2;
		m++;
	}
	cin.get();
}