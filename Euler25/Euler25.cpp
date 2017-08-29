#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;
void main() {
	int overflow = 0;
	int* fib1 = new int[1001];
	int* fib2 = new int[1001];
	int greatestDigit = 1;// not in arrray form
	int currentDigit = 0;//in array form ie the 1th digit of 12 is 1
	int nthTerm = 2;
	fib1[0] = 1;
	fib2[0] = 1;
	while (greatestDigit < 1000) {
		while (currentDigit < greatestDigit) {
			fib2[currentDigit] = fib2[currentDigit] + fib1[currentDigit];
			fib1[currentDigit] = fib2[currentDigit] - fib1[currentDigit];
			fib2[currentDigit] += overflow;
			if (fib2[currentDigit] > 9) {
				overflow = 1;
				fib2[currentDigit] = fib2[currentDigit] % 10;
				if (currentDigit + 1 == greatestDigit) {
					fib1[currentDigit + 1] = 0;
					fib2[currentDigit + 1] = 1;
					greatestDigit++;
					break;
				}
			}
			else {
				overflow = 0;
			}
			currentDigit++;
		}
		overflow = 0;
		nthTerm++;
		if (nthTerm == 12) {
			printArray(greatestDigit, fib2);
		}
		currentDigit = 0;
	}
	printArray(greatestDigit, fib2);
	printf("The answer is %d", nthTerm);
	cin.get();
}
void printArray(int length, int* numArray) {
	//prints an array of numbers
	int i = length-1;
	while (i > -1) {
		printf("%d", numArray[i]);
		i--;
	}
	printf("\n");
}