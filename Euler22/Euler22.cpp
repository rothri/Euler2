#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void main() {
	const int maxlength = 2;
	const char * fn = "C:\\Users\\montr_000\\Desktop\\Ex_Files_Cpp_EssT\\p022_names.txt";
	const char * type = "r";
	FILE * fr;
	char buf[maxlength];
	fopen_s(&fr, fn, type);
	char name[20];
	int i = 0;
	int count = 0;
	string* names = new string[5163];
	while (fgets(buf, maxlength, fr)){
		if (*buf != '"' && *buf !=' ') {
			if (*buf != ',') {
				name[i] = *buf;
				i++;
			}
			else {
				name[i] = 0;
				i = 0;
				names[count] = name;
				count++;
			}
		}
	}
	name[i] = 0;
	names[count] = name;
	i = 0;
	int k = 0;
	long answer = 0;
	long sum = 0;
	long letter =1;
	string word;
	std::sort(names, names+5163);
	while (i <= count) {
		printf("\n%s",names[i].c_str());
		k = 0;
		sum = 0;
		word = names[i];
		while (letter != -64) {
			letter = long(word[k]);
			if (letter == 0) {
				break;
			}
			letter = letter - 64;
			sum += letter;
			k++;
		}
		printf(" %d", (i+1)*sum);
		answer += (1+i)*sum;
		i++;
	}
	printf("\n The answer is %d", answer);
	fclose(fr);
	cin.get();
}