#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream file;
	string line;
	file.open("C:\\Users\\montr_000\\Desktop\\Ex_Files_Cpp_EssT\\numbers.txt",ios::in);
	int count = 0;
	long long sum = 1;
	long long answer=0;
	long long last[14];
	long long loopcontrol = -8;
	while (getline(file, line)) {
		loopcontrol += 8;
		int i = 0;
		while (i < 50) {
			int num = (long long)line[i]-48;
	
			if (num != 0) {
				last[(i + loopcontrol) % 14] = (long long)line[i] - 48;
				count++;
				sum *= num;
				if (count > 13) {
					sum /= last[(loopcontrol + i + 1) % 14];
				}
				
				if (count >= 13){
					if (answer < sum) {
						answer = sum;
					}
				}
			}
			else {
				count = 0;
				sum = 1;
				last[(i + loopcontrol) % 14] = 0;
			}
			i++;
		}
		
	}
	printf("The answer is: %I64d\n", answer);
	cin.get();
}