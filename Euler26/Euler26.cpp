#include <cstdio>
#include <iostream>
using namespace std;
void main() {
	int i = 1;
	int numer = 10000;
	int * repeat = new int[5000];
	int k = 0;
	int j = 0;
	int ansLength = 0;
	int lastRepeat = 0;
	int answer = 0;
	bool check = false;
	while (i < 1000) {
		numer = 10000;
		while (numer / i > 9) {
			numer /= 10;
		}
		k = 0;
		check = false;
		lastRepeat = 0;
		while (numer % i != 0 ) {
			if (k == 5000) {
				k = 0;
				printf("Something went wrong probably\n");
				break;
			}
			else {
				repeat[k] = numer / i;
				numer = (numer%i) * 10;
			}
			if (check) {
				j++;
				if (lastRepeat == numer) {
					if (j > ansLength) {
						ansLength = j;
						answer = i;
						printf("New answer: ");
					}
					printf("%d has repeating length %d\n", i, j);
					break;
				}
			}
			if (k == 100) {
				check = true;
				lastRepeat = numer;
				j = 0;
			}
			if (numer % i == 0) {
				printf("%d divides evenly with %d digits\n", i, k);
			}
			k++;
		}
		i++;
	}
	printf("\n The answer is %d", answer);
	printf("\n with length %d", ansLength);
	cin.get();
}