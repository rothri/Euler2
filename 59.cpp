#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;
void e59(){
     string line;
	 int numArr[4000];
	 fill(numArr,numArr+4000,-1);
	 int j=0;
	 bool second = false;//if there is a second number before a comma this is true
	 fstream myfile ("cipher.txt");
	  if (myfile.is_open())
  {
		while ( getline (myfile,line) ){
			  if(numArr[j]!=-1){
				  j++;
			  }
			  for(int i=0; i<line.length(); i++){
				  if(line[i]==','){
					  j++;
					  second=false;
				  }else{
					  if(second){
						  numArr[j]*=10;
						  numArr[j]+=(int)line[i] -48;
					  }
					  else{
						  numArr[j]=(int)line[i] -48;
						  second=true;
					  }
				  }
			  }
		}

		myfile.close();
	  }
		int i,sum=0;
		int a =97, b=97, c=97;
		int z=122;
		int decodeArr[4000];
		memcpy(decodeArr,numArr,sizeof(numArr));
		while(a<=z){
			b=97;
			while(b<=z){
				c=97;
				while(c<=z){
					sum=0;
					fill(decodeArr,decodeArr+4000,-1);
					memcpy(decodeArr,numArr,sizeof(numArr));
					for(i=0;decodeArr[i]!=-1;i++){
						switch(i%3){
						case 0:
							decodeArr[i]^=a;
							break;
						case 1:
							decodeArr[i]^=b;
							break;
						case 2:
							decodeArr[i]^=c;
							break;
						}
						if(decodeArr[i]<32||decodeArr[i]>126){
							break;
						}

						sum+=decodeArr[i];
					}
					if(decodeArr[i]==-1){
						//means we decoded the whole thing
						for(i=0;decodeArr[i]!=-1;i++){
							if(decodeArr[i]==116 && decodeArr[i+1]==104 && decodeArr[i+2]==101){
								cout<<"Possible Solution with code"<<a<<","<<b<<","<<c<<" and answer:"<<sum<<"\n";
								break;
							}
						}
					}
					c++;
				}
				b++;
			}
			a++;
		}
	  cin.get();
}