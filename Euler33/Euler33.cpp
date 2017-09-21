#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;
void main() {
	int  numer[2] = { 1,0 };
	int denomer[2] = { 1,1};
	int last = 0;
	while (numer[0] < 10) {
		while (denomer[0] < 10) {
			if (denomer[0] == numer[1]) {
				last = DivideInt(numer[1] + numer[0] * 10, denomer[1] + denomer[0] * 10, 5);
				if (last == (DivideInt(numer[0], denomer[1], 5)) ){
					printf("\n%d = %d\n", numer[1] + numer[0] * 10, numer[0]);
					printf("----------------\n");
					printf("%d = %d\n",denomer[0]*10+denomer[1],denomer[1]);
				}
			}
			denomer[1]++;
			if (denomer[1] == 10) {
				denomer[0]++;
				denomer[1] = 0;
			}
		}
		numer[1]++;
		if (numer[1] == 10) {
			numer[1] = 0;
			numer[0]++;
		}
		denomer[0] = numer[0];
		denomer[1] = numer[1]+1;
		if (denomer[1] == 10) {
			denomer[0]++;
			denomer[1] = 0;
		}
	}
	printf("\nThe answer is 1/100");
	cin.get();
}

int DivideInt(int num, int denum, int digits) {
	//returns the fraction of num/dnum in the form of an integer of at most n digits.
	// cant tell the difference between 0.13333 and 1.3333333 as all begining 0 arent included and the decimal point as well
	int i = 0;
	int answer =0;
	int remain = 0;
	if (denum == 0 || num == 0) {
		return 0;
	}
	while (i <= digits) {
		if (num < denum) {
			num *= 10;
			answer *= 10;
		}
		else {
			answer *= 10;
			remain = num%denum;
			num = num / denum;
			answer += num;
			if (remain == 0) {
				break;
			}
			num =remain*10;	
		}
		i++;
	}
	return answer;
}