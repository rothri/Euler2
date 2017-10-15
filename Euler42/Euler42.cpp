#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;

void main() {
	string line;
	const char * fn = "C:\\Users\\montr_000\\Desktop\\Ex_Files_C_Sharp_EssT\\p042_words.txt";
	ifstream  myFile (fn);
	long wordnum = 0;
	int count = 0;
	if (myFile.is_open())
	{
		int i = 0;
		while (getline(myFile, line))
		{
			i = 0;
			while (line[i] != 0) {
				if (line[i] != '"' && line[i] != ',') {
					wordnum += long(line[i])-64;
					
				}
				if (line[i] == ',') {
					if (isTriangleNumber(&wordnum)) {
						count++;
					}
					wordnum = 0;
				}
				i++;
			}
		}
		if (isTriangleNumber(&wordnum)) {
			count++;
		}
		myFile.close();
	}
	printf("The answer is %d", count);
	cin.get();
}

bool isTriangleNumber(long * num) {
	long n = 1;
	long tn = 0;
	while (tn < *num) {
		tn = (n*n + n) / 2;
		if (tn == *num) {
			return true;
		}
		n++;
	}
	return false;
}