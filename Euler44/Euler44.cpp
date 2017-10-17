#include <cstdio>
#include <iostream>
#define numLength 5000
using namespace std;

void main() {
	long long   pNums[numLength];
	long long n = 1;
	int i = 0;
	int k = 0;
	long long max = 0;
	long long diff = 0;
	long long sum = 0;
	bool check = false;
	bool answer = false;
	while (i < numLength) {
		pNums[i] = (n*(3 * n - 1)) / 2;
		i++;
		n++;
	}
	max = pNums[numLength-1];
	i = 0;
	int j = 0;
	while (i < numLength) {
		n = pNums[i];
		k = 0;
		while (k < i) {
			j = 0;
			diff = n - pNums[k];
			sum = n + pNums[k];
			check = true;
			if (sum > max) {
				printf("Max has been reached \n");
				break;
			}
			while (j < numLength) {
				if (pNums[j]>diff && check) {
					break;
				}
				if (pNums[j] == diff) {
					check = false;
				}
				if (pNums[j] == sum) {
					printf("Answer found:%I64d", diff);
					printf("\n This is the difference between %I64d and %I64d Which are p(%d) and p(%d)", n, pNums[k], i, k);
					answer = true;
					break;
				}
				if (pNums[j] > sum) {
					break;
				}
				j++;
			}
			k++;
		}
		i++;
		if (answer) {
			break;
		}
	}
	printf("Done! \n");
	cin.get();
}