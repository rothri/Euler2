#include <cstdio>
#include <iostream>
#include "Header.h"
using namespace std;

void main(){
	int count = 0;
	int answer = 0;
	int coins[] = { 0,0,0,0,0,0,0 };
	while (coins[0] < 201) {
		while (coins[1] <101) {
			count = countTotal(coins);
			if (count >200) {
				coins[2] = 0;
				coins[3] = 0;
				coins[4] = 0;
				coins[5] = 0;
				coins[6] = 0;
				break;
			}
			while (coins[2] < 41) {
				count = countTotal(coins);
				if (count >200) {
					coins[3] = 0;
					coins[4] = 0;
					coins[5] = 0;
					coins[6] = 0;
					break;
				}
				while (coins[3] <21) {
					count = countTotal(coins);
					if (count >200) {
						coins[4] = 0;
						coins[5] = 0;
						coins[6] = 0;
						break;
					}
					while (coins[4] < 11) {
						count = countTotal(coins);
						if (count >200) {
							coins[5] = 0;
							coins[6] = 0;
							break;
						}
						while (coins[5] < 5) {
							count = countTotal(coins);
							if (count >200) {
								coins[6] = 0;
								break;
							}
							while (coins[6] < 3) {
								count = countTotal(coins);
								if (count >200) {
									break;
								}
								if (count == 200) {
									answer++;
									break;
								}
								coins[6]++;
							}
							coins[5]++;
							coins[6] = 0;
						}
						coins[4]++;
						coins[5] = 0;
					}
					coins[3]++;
					coins[4] = 0;
				}
				coins[2]++;
				coins[3] = 0;
			}
			coins[1]++;
			coins[2] = 0;
		}
		coins[0] ++;
		coins[1] = 0;
	}
	answer += 1;//coin 200
	printf("The answer is %d", answer);
	cin.get();
}
int countTotal(int  coins[]) {
	int i = 0;
	int sum = 0;
	sum += coins[0];
	sum += coins[1] * 2;
	sum += coins[2] * 5;
	sum += coins[3] * 10;
	sum += coins[4] * 20;
	sum += coins[5] * 50;
	sum += coins[6] * 100;
	return sum;
}