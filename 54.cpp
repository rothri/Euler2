#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include <algorithm>
using namespace std;
void main(){
	 string line;
  fstream myfile ("poker.txt");
  card cArr[10];
  int hand1=0;
  int hand2=0;
  int j=0;//used to populate card array
  if (myfile.is_open())
  {
	  while ( getline (myfile,line) )
    {
		for(int i=0;i<line.length();i++){
      if(line[i] !=' '){//double quotes are for c-Strings
		  if(!isdigit(line[i])){
			if(line[i]=='A'){
				  cArr[j].value=14;
			  }else if (line[i]=='K'){
				 cArr[j].value=13;
			  }else if (line[i]=='Q'){
				  cArr[j].value=12;
			  }else if (line[i]=='J'){
				  cArr[j].value=11;
			  }else if(line[i]=='T'){
				  cArr[j].value=10;
			  }else{
				  cArr[j].suit=line[i];
				  if(j==9){
				  j=0;
				  if(findWinner(cArr)){
					  hand1++;
				  }else{
					  hand2++;
				  }
			  }
			  }
		  }else{
			  cArr[j].value=(int)line[i] -48;

			}
		}
		  else{
			  j++;
		  }
	}
    }
    myfile.close();
  }
  std::cout<<hand1;
	std::cin.get();
	return;
}
bool findWinner(card * cArr){
	//takes 2 hands of 5 cards and returns true if the first 5 are the winner
	card hand1[5]={cArr[0],cArr[1],cArr[2],cArr[3],cArr[4]};
	card hand2[5]={cArr[5],cArr[6],cArr[7],cArr[8],cArr[9]};
	int * rank2= detectHand(hand1);
	int rank1[5]={rank2[0],rank2[1],rank2[2],rank2[3],rank2[4]};
		  rank2= detectHand(hand2);
	for (int i=0;i<6;i++){
		if (rank1[i]>rank2[i]){
			return true;
		}
		if (rank1[i]<rank2[i]){
			return false;
		}
	}
	std::cout<<"There was a hand the returned ina draw \n";
	return true;
}
int* detectHand(card *cArr){
		bool straight=true;
		bool flush=true;
		int num1= cArr[0].value;
		int num2= cArr[1].value;
		int num3= cArr[2].value;
		int num4= cArr[3].value;
		int num5= cArr[4].value;
		int hand[5] ={num1,num2,num3,num4,num5};
		int i=0;
		int j=0;
		int matches=0;
		int rank=0;
		//7=pair
		//9=2pair
		//11=3of a kind
		//13=full house
		//17= four of a kind
		while(i<5){
			j=0;

			while(j<5){

				if (hand[i]==hand[j]){
					matches+=1;
					if (i!=j){
						if(rank<hand[i]){
							rank=hand[i];
						}
						//only overwritten by the same pair
						//or if there is 2 pairs
					}
				}

				j+=1;
			}

			i+=1;
		}
		//straight
		sort(hand, hand+5);

		if (hand[0]!=2){
			i=1;
			while(i<5){
				if (hand[i-1]+1 !=hand[i]){
					straight=false;
					break;
				}
				i+=1;
			}
		}
		else{
			straight=false;
			if (hand[1]==3 && hand[2]==4){//hand[0] is king hand[1] is ace and hand[2] is 10
				if(hand[3]==5 && hand[4] == 6){
					straight=true;
				}
				if(hand[3]==5 && hand[4] ==14){
					straight=true;
				}
			}
		}
		//flush
		int suit= (cArr[0].suit);

		if(suit!=(cArr[1].suit)){
			flush=false;
		}
		if(suit!=(cArr[2].suit)){
			flush=false;
		}
		if(suit!=(cArr[3].suit)){
			flush=false;
		}
		if(suit!=(cArr[4].suit)){
			flush=false;
		}
		//im a lazy person


		if(straight&&flush){
			if(hand[4]!=14){
				rank=hand[4];
			}
			else{
				if (hand[0]==2){
					rank=5;
				}
				else{
					rank=14;
				}
			}
			if (hand[0]==10){
			int result[6]={9,rank,hand[4],hand[3],hand[2],hand[1]};
			return result;
			}
			int result[6]={8,rank,hand[4],hand[3],hand[2],hand[1]};
			return result;
		}
		if (matches==17){
			int result[6]={7,rank,hand[4],hand[3],hand[2],hand[1]};
			return result;
		}
		if (matches==13){
			int result[6]={6,rank,hand[4],hand[3],hand[2],hand[1]};
			return result;
		}
		if(flush){
			int result[6]={5,hand[4],hand[3],hand[2],hand[1],hand[0]};
			return result;
		}
		if(straight){
			if(hand[4]!=14){
				rank=hand[4];
			}
			else{
				if (hand[0]==2){
					rank=5;
				}
				else{
					rank=14;
				}
			}
			int result[6]={4,rank,hand[3],hand[2],hand[1],hand[0]};
			return result;
		}
		if (matches==11){
			int result[6]={3,rank,hand[4],hand[3],hand[2],hand[1]};
			return result;
		}
		if (matches==9){
			int result[6]={2,rank,hand[4],hand[3],hand[2],hand[1]};
			return result;
		}
		if (matches ==7){
			int result[6]={1,rank,hand[4],hand[3],hand[2],hand[1]};
			return result;
		}
		int result[6]={0,hand[4],hand[3],hand[2],hand[1],hand[0]};
		return result;
	}