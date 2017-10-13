#include <cstdio>
#include <iostream>

using namespace std;

void main() {
	int digit = 0;
	int numbers[10] = { 0,0,0,0,0,0,0,0,0,0};
	bool overflow = false;
	int check = 1;
	int largestDigit = 1;
	int i = 0;
	int answer = 1;
	while (check <= 1000000) {
		i = 0;
		numbers[0]++;
		while (i < largestDigit) {
			digit++;
			if (overflow) {
				numbers[i]++;
			}
			overflow = false;
			if (numbers[i] >9) {
				overflow = true;
				numbers[i] = numbers[i] % 10;
				if (i + 1 == largestDigit) {
					largestDigit++;
				}
			}
			if (digit == check) {
				if (overflow) {
					//This is cheating
					answer *= 1;
					if (numbers[largestDigit - i - 1] != 0) {
						printf("Something probably went wrong at n=%d\n", digit);
						answer *= numbers[largestDigit - i - 1];
						printf("%d was included\n", numbers[largestDigit - i - 1]);
					}
					check *= 10;
				}
				else {
					printf("%d\n", numbers[largestDigit - i-1]);
					answer *= numbers[largestDigit - i-1];
					check *= 10;
				}
			}
			i++;
		}
	}
	printf("The answer is %d", answer);
	// lessons to learn from this program.
	// solve the problem the way you would on paper.
	cin.get();
}