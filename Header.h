struct card{
	int value;
	char suit;
};
bool nchooser(int n, int r);
long long int factorial(int n,int r);
void populateArray(int * arr, int n, int r);
long long int calcArray(int * arr);
bool findWinner(card * cArr);
int* detectHand(card* cArr);
bool isNumArrPalindrome(int* numArr,int lastDigit);
int intArrAdd(int* arr1,int* arr2);
void reverseNumArr(int* arr1,int*arr2,int lastDigit);