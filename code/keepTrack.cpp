#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>



using namespace std;


	
	int keepTrack(int year, int month, int day){
		
		
		int norm[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
		int leap[13]={0,31,60,91,121,152,182,213,244,274,305,335,366}, le;
		int numOfDays;		
		
		if(year%4 == 0 && year%100 != 0){le=1;}
		 
		else if(year%100==0){le=0;}
		else if(year%400==0){le=1;}
		else{le=0;}
		
		
		if(le==1){
			
			numOfDays=leap[month-1]+day;		
			
		}
		else{
			numOfDays=norm[month-1]+day;
						
		}
		
		return numOfDays;
}
