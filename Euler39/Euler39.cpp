#include<cstdio>
#include<iostream>
#include <cmath>
using namespace std;

void main() {
	int p = 100;
	int a = 0;
	int b = 0;
	int c = 0;
	int count = 0;
	int highCount = 0;
	int answer = 0;
	while (p <= 1000) {
		a = 0;
		count = 0;
		while (a < p / 2) {
			b = 1;
			while (b < p-a) {
				c = sqrt(a*a + b*b);
				if (c*c == a*a + b*b) {
					if (a + b + c == p) {
						count++;
					}
				}
				b++;
			}
			a++;
		}
		if (count > highCount) {
			highCount = count;
			answer = p;
		}
		p++;
	}
	printf("The answer is %d", answer);
	cin.get();
}