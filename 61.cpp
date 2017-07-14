#include "Header.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
;
using namespace std;
geoNum tri[500]={0};
geoNum squ[500]={0};
geoNum pent[500]={0};
geoNum hexa[500]={0};
geoNum hept[500]={0};
geoNum octa[500]={0}; 
geoNum *nums[6]={tri,squ,pent,hexa,hept,octa};
int answer=0;;
void e61(){
	int n=1;
	int num=0;
	while((n*(n+1))/2<10000){
		num=(n*(n+1))/2;
		if (num>999 && num<10000){
			tri[n].first2=num/100;
			tri[n].last2=num%100;
		}
		num=(n*n);
		if (num>999 && num<10000){
			squ[n].first2=num/100;
			squ[n].last2=num%100;
		}
		num=(n*(3*n-1))/2;
		if (num>999 && num<10000){
			pent[n].first2=num/100;
			pent[n].last2=num%100;
		}
		num=(n*(2*n-1));
		if (num>999 && num<10000){
			hexa[n].first2=num/100;
			hexa[n].last2=num%100;
		}
		num=(n*(5*n-3))/2;
		if (num>999 && num<10000){
			hept[n].first2=num/100;
			hept[n].last2=num%100;
		}
		num=(n*(3*n-2));
		if (num>999 && num<10000){
			octa[n].first2=num/100;
			octa[n].last2=num%100;
		}
		n++;
	}
	for(int i=0; i<6;i++){
	sort(nums[i],nums[i]+499,geoNumCompare);
		//sort(tri,tri+499,geoNumCompare);
	}
	int i=0;
	int numList[6][3];
	for (int i=0;i<6;i++){
		for (int j=0;j<3;j++){
			numList[i][j]=-1;
		}
	}
	while(tri[i].first2!=0){
		numList[0][0]=tri[i].first2;
		numList[0][1]=tri[i].last2;
		numList[0][2]=0;
		findConnections(*numList);
		i++;
		if(answer !=0){
			break;
		}
	}
	cout<<answer;
	cin.get();
}
//get last 2 digits
//get first 2 digits
//store this information then iterate through
//sort by first 2 digits

//numlist fnum 2num order
bool geoNumCompare(geoNum a, geoNum b) { return a.first2 > b.first2; };//we want biggest numbers first
void findConnections(int  *numList){
	int newList[6][3] ={0};
	for (int i=0;i<6;i++){
		for (int j=0;j<3;j++){
			newList[i][j]=numList[i*3+j];
		}
	}
	if(answer!=0){
		return;
	}
	int i=0;
	int orderNum=0;
	int place=0;
	while (i<6){//find the last number used in the chain and assign its location to place
		if (newList[i][2] > orderNum){
			orderNum=newList[i][2];
			place=i;
		}
		i++;
	}
	i=0;
	while(i<6){
		if(newList[i][2] < 0){//this geonum is not being used yet
			int j=0;
			while(nums[i][j].first2>0){
				if(i==6){
					i=6;
				}
				if(newList[place][1]==nums[i][j].first2){
					if(orderNum == 4){
						if (newList[0][0]==nums[i][j].last2){
							for(int k=0;k<6;k++){
								if(newList[k][0]>0){
									answer+=100*newList[k][0];
									answer+=newList[k][1];
								}
								else{
									answer+=nums[i][j].last2;
									answer+=100*nums[i][j].first2;
								}
							}
							return;
						}
					}
					else{
						newList[i][0]=nums[i][j].first2;
						newList[i][1]=nums[i][j].last2;
						newList[i][2]=orderNum+1;
						findConnections(*newList);
						newList[i][0]=-1;
						newList[i][1]=-1;
						newList[i][2]=-1;
					}
				}
				j++;
			}
		}
		i++;
	}
	return;
};