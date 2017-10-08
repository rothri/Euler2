#include <iostream>
#include <cstdio>
#include "Header.h"
using namespace std;

void main(){
	long i = 1;
	long sum = 0;
	while (i < 1000000) {
		if (isPalindromeB10(i)) {
			if (isPalindromeB2(i)) {
				sum += i;
				printf("Palindrome:%d\n", i);
			}
		}
		i++;
	}
	printf("The answer is %d", sum);
	cin.get();
}
bool isPalindromeB10(long num) {
	// returns true if a non negative number is a palindrome
	long i = 0;
	while (i < num) {
		if (i == 0) {
			i = 1;
		}
		else {
			i *= 10;
		}
	}
	long k = 1;
	bool palin = true;
	while (k < i && palin) {
		i /= 10;
		if ((num / i) % 10 !=(num/k)%10 ) {
			palin = false;
		}
		k *= 10;
	}
	return palin;
}
bool isPalindromeB2(long num) {
	if (num == 0) {
		return false;
	}
	long left = 0;
	long right = 0;
	int offset = 32;
	while (left == 0) {
		offset--;
		left = num >> offset;
	}
	int i = 1;
	offset++;
	bool check = true;
	while (i <= ( offset) / 2 && check) {
		left = num >> (offset - i);
		left = left << (31);
		left =left >> 31;
		right = num << (32 - i);
		right = right >> 31;
		left *= left;
		right *= right;
		i++;
		if (right != left) {
			check = false;
		}
	}
	return check;
}