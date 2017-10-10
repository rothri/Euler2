#include <cstdio>
#include <iostream>

using namespace std;

void main() {
	//LOGIC TIME
	// first i tried the number 9. This gives 9 18 27 36 45 which is incorrect, but tells us that the number is between
	// 987654321 and that
	//now we could try a 2 digit number,but it would have to start with 9 and therefore the next numbers
	// would be 3 digits and 2+3+3=8, so every answer generated would be too short/long
	//same logic for a 3 digit num starting with 9 3+4+4 =11
	// a 4 digit number works because 4 +5 =9
	//starting 9000 we get 18000 we want the next digit to be as high as possible, but it cant be above 4
	// since the overflow would give us 2 9s
	//9400*2 =18800 so we need to elminate the 2nd 8.
	// through quick exhaustion starting with 7, then 6 it becomes clear this is impossible so 3
	// it was actually kinda quick since the numbers cant be selected twice
	// 9300*2 =18600 
	// we need to calculate a 5 in the next number since we cant use a 5 in the first.
	//we cant use the  the last digit since no number *2 =5 so we need a 2 and overflow the next digit
	//9320*2=18640 
	// our next highest digit is 7 and trying that works.
	//Thinking of this took me way less time than to program it
	//and type this out, so this is what i did
	printf("The answer is %d", 932718654);
	cin.get();
}