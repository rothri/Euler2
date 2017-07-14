#include <iostream>
#include "Header.h"
using namespace std;
void e57(){
	long long int num=7;
	long long int denom=5;
	int i=2;
	int answer=0;
	long long int swap=0;
	int numLength=1;
	int denomLength=1;
	while(i<1000){
		i++;
		num-=denom;
		num+=2*denom;

		//1/(1/2)=2/1
		swap=num;
		num=denom;
		denom=swap;
		num+=denom;
		numLength=greatestDigit(num);
		denomLength=greatestDigit(denom);
		if(numLength>denomLength){
			cout<<num<<"//"<<denom<<"\n";
			answer++;
		}
	}
	cout<<answer;
	cin.get();
	//There was much overflow, this code should not have worked!

}
int greatestDigit(long long int i){
	int digit=1;
	long long int powTen=10;
	while(i/powTen !=0){
		powTen*=10;
		digit++;
	}
	return digit;
}