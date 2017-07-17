#include "Header.h"
#include <stdio.h>
#include <iostream>
;
using namespace std;
void e64 (){
	int x=0;
	int count=0;
	long int digits=1;
	int power=0;
	long int number=0;
	while (power<30){
		power++;
		x=0;
		while(x<9){
			x++;
			number=1;
			digits=1;
			for(int i=0;i<power;i++){
				number*=x;
				digits*=10;
			}
			if(number<digits && number>= digits/10){
				count++;
			}
		}
	}
	cout<<count;
	cin.get();
}