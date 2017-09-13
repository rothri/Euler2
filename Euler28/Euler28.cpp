#include <cstdio>
#include <iostream>

using namespace std;
void main() {
	// screw using a 2d array
	long answer = 1;
	int count = 0;
	long currentNum = 1;
	int space = 2;
	while (space < 1001) {
		currentNum += space;
		answer += currentNum;
		count++;
		if (count == 4) {
			count = 0;
			space += 2;
		}
	}
	printf("The answer is %d", answer);
	cin.get();
}