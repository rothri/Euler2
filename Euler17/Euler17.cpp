#include <cstdio>
#include <iostream>

using namespace std;

void main() {
	int x=0;
	long sum=0;
	while (x < 1000){
		x++;
		switch (x%10) {
		case 1 : 
			sum += 3;
			break;
		case 2 :
			sum += 3;
			break;
		case 3 :
			sum += 5;
			break;
		case 4 :
			sum += 4;
			break;
		case 5 :
			sum += 4;
			break;
		case 6:
			sum += 3;
			break;
		case 7 :
			sum += 5;
			break;
		case 8 :
			sum += 5;
			break;
		case 9:
			sum += 4;
			break;
		}
		switch (((x % 100)-x%10)/10) {
		case 1:
			switch (x % 10) {
			case 0:
				sum += 3;
				break;
			case 1:
				sum += 3;
				break;
			case 2:
				sum += 3;
				break;
			case 3:
				sum += 3;
				break;
			case 4:
				sum += 4;
				break;
			case 5:
				sum += 3;
				break;
			case 6:
				sum += 4;
				break;
			case 7:
				sum += 4;
				break;
			case 8:
				sum += 3;
				break;
			case 9:
				sum += 4;
				break;
			}
			break;
		case 2:
			sum += 6;
			break;
		case 3:
			sum += 6;
			break;
		case 4:
			sum += 5;
			break;
		case 5:
			sum += 5;
			break;
		case 6:
			sum += 5;
			break;
		case 7:
			sum += 7;
			break;
		case 8:
			sum += 6;
			break;
		case 9:
			sum += 6;
			break;
		}
		switch (x / 100) {
		case 1:
			sum += 3;
			sum += 7;
			break;
		case 2:
			sum += 3;
			sum += 7;
			break;
		case 3:
			sum += 5;
			sum += 7;
			break;
		case 4:
			sum += 4;
			sum += 7;
			break;
		case 5:
			sum += 4;
			sum += 7;
			break;
		case 6:
			sum += 3;
			sum += 7;
			break;
		case 7:
			sum += 5;
			sum += 7;
			break;
		case 8:
			sum += 5;
			sum += 7;
			break;
		case 9:
			sum += 4;
			sum += 7;
			break;
		case 10:
			sum += 11;
			break;
		}
		//printf("X is %d  Sum is %d\n", x, sum);
		//if (x == 125) {
		//	break;
		//}
	}
	sum = sum + 891 * 3;
	printf("The answer is %d", sum);
	cin.get();
}