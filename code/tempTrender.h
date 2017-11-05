#ifndef TEMPTRENDER_H 
#define TEMPTRENDER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


#include <TF1.h> 
#include <TH1.h> 
#include <TStyle.h>  
#include <TMath.h>   
#include <TCanvas.h> 
#include <THStack.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TColor.h>
#include <TAttFill.h>
#include "keepTrack.cpp"

using namespace std;

class tempTrender {
	public:
	tempTrender(string filePath); //Construct using the specified file
	~tempTrender();//Destructor
	
	vector<string> data_from_file; // Will store every meaningful line from the datasets.
	vector <float> datavector,urbanDatavector,avgOfData, urbanAvgOfData;
	vector <float> yearTemp, urbanYearTemp, yearNumber;
	vector <float> warmAndCold;
	float meanTempEveryYear;
	
	vector<string> read_temperatures(){
	// Let's read a file and store lines with data in a vector and sort them then store them in a new datafile.
		
		//These variables are used with stringstream later on to extract the relevant data from the raw data.
		float yyyy, mm, dd, hour, min, sec, temperature,urbanTemp, control;
		char d;
		
		// Variables that are used to fill up the vector.
		string input, temp, useless_line; 
		
		ifstream file(its_filePath.c_str());
		ofstream datafile("relevantdata.dat"); 
		 
		 
		if(its_filePath == "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat"){
			
			
			while(getline(file,temp)){
				stringstream data;
				data << temp;
				data >> yyyy >> mm >> dd >> temperature >> urbanTemp >> control;
				//if (control == 1){
				datafile << yyyy << " " << mm << " " << dd << " " << temperature << " " << urbanTemp << endl;
				//}
			}
		}		
		
		else {
			//Skipping the first few lines, which only contain text.
			while(getline(file,useless_line)){
				
				if (useless_line == "Datum;Tid (UTC);Lufttemperatur;Kvalitet;;Tidsutsnitt:"){
					break;
				}	
			}
			
			while(getline(file,temp)){
				
				// Lines are split up into substrings such that the last part of some lines is removed.
				// Then lines with Y (bad recordings) are excluded by identifying those and erasing the line.
				input = temp.substr(0,temp.find(";;",0));
				size_t pos = input.find("Y");
				input.erase(0,pos +1);
				
				//Using stringstream below, the raw data is split up and the relevant parts are extracted.
				stringstream data;
				
				//This is to only feed non-empty lines into the .dat file.
				if(input != ""){
					
					//The data here is segmented into the format given in the raw data files, to allow for easy extraction.
					//d sipmly signifies the delimiter between the numbers in the files.
					data << input;
					data >> yyyy >> d >> mm >> d >> dd >> d >> hour >> d >> min >> d >> sec >> d >> temperature >> d ;
					datafile << yyyy << " " << mm << " " << dd << " " << hour << " " << temperature << endl;				
					data_from_file.push_back(input);
				}
			
			}
		}
		datafile.close();
		file.close();
		
		return data_from_file;
		
	}
	
	
	
	
	//void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	//void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	//void tempPerDay(); //Make a histogram of the average temperature of each day of the year
	
	
	
	
	//Tentative function
	vector <float> tempPerDay(int yearToCalculate){
		// This function takes a year as input, computes the average temperature of each day in that year and produces a histogram of mean temperature per day.
		
		ifstream f("relevantdata.dat"); // Opening the organized datafile produced in read_temperatures().
		string line; 
		
		
		// Variables used to fill a datavector (in turn used to produce the histogram) with mean temperatures corresponding to each day in the chosen year:
		float temperature, urbanTemp, mean_temp, urbanMean_temp, tot_temp = 0, urbanTot_temp =0; 
		
		// Don't know what the first day in the file is. Give old_day a "wrong" initial value, then give it the day value read in each new line.
		int old_day = 0, old_year=0, measurementNo = 0, start=0, yyyy, mm, dd, hour, old_month=0;
		char d;
		
		int number_of_days = ::keepTrack(yearToCalculate, 12, 31);
		
		for(int k=0; k<number_of_days; k++){
			datavector.push_back(0);	
			urbanDatavector.push_back(0);	
		}
		
		if(its_filePath == "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat"){
			
			
			while (getline(f, line)){
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> temperature >> urbanTemp;
			
				//cout << "uppsala" << endl;
				
				if ((yyyy == yearToCalculate) || (yyyy == yearToCalculate + 1)){ // Checking that we are in the right year. year+1 condition is needed for the las day of the year.
					//cout << yyyy << endl;
					if ((old_day == dd) || (old_day == 0)){ // As long as the day is the same as in the previous line, add the temperature to a temporary total.
						tot_temp += temperature;
						//cout << tot_temp << endl;
						urbanTot_temp += urbanTemp;
						//cout << urbanTot_temp << endl;
						measurementNo += 1;
						old_day = dd;
						old_month = mm;
					}
					
					else {
						mean_temp = tot_temp / measurementNo; // When the day changes, divide the (temporary) total by the corresponding number of read lines.
						urbanMean_temp = urbanTot_temp /measurementNo;
						datavector[::keepTrack(yearToCalculate, old_month,old_day) -1]=mean_temp; // Store the mean in the datavector.
						urbanDatavector[::keepTrack(yearToCalculate, old_month, old_day) -1] = urbanMean_temp;
						old_day = dd; 
						old_month = mm;
						measurementNo = 1; // Reset (temporary) temperature total and corresponding number of read lines.
						tot_temp = temperature;
						urbanTot_temp = urbanTemp;
					}
					
				}
				
				
				if ( yyyy == yearToCalculate + 1){ // Kill the above process once a new year is reached.
					break;
				}
					
			}
		}
		
		else{
			
			while (getline(f, line)){
				// The while loop goes through every line in the datafile. It adds up temperatures until a new day is reached, then takes the mean of these and outputs it in the datavector.
				
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> hour >> temperature;
				//cout << "notupp" << endl;
				//cout << yyyy <<" "<< mm <<" "<< dd <<" "<< hour <<" " << temperature << endl;
				
				if ((yyyy == yearToCalculate) || (yyyy == yearToCalculate + 1)){ // Checking that we are in the right year. year+1 condition is needed for the las day of the year.
					
					if ((old_day == dd) || (old_day == 0)){ // As long as the day is the same as in the previous line, add the temperature to a temporary total.
						tot_temp += temperature;
						//cout << tot_temp << endl;
						measurementNo += 1;
						old_day = dd;
						old_month = mm;
					}
					
					else {
						mean_temp = tot_temp / measurementNo; // When the day changes, divide the (temporary) total by the corresponding number of read lines.
						datavector[::keepTrack(yearToCalculate, old_month,old_day) -1]=mean_temp; // Store the mean in the datavector.
						old_day = dd; 
						old_month = mm;
						measurementNo = 1; // Reset (temporary) temperature total and corresponding number of read lines.
						tot_temp = temperature;
					}
					
				}
				
				
				if ( yyyy == yearToCalculate + 1){ // Kill the above process once a new year is reached.
					break;
				}
				
			}	
			f.close();
		}
		return datavector, urbanDatavector;

	}
	
	//void hotCold(); //Make a histogram of the hottest and coldest day of the year
	//void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year
	
	
	
	
	
	void tempEveryYear(){
		
		
		ifstream datafile("relevantdata.dat");
		string line;
		
		float temperature, urbanTemp, avgTemp, urbanAvgTemp, tot_temp = 0, urbanTot_temp = 0;
		int yyyy, mm, dd, hour, measurementNo = 0, old_year=0;
		float tot_TempEveryYear = 0;
		meanTempEveryYear = 0;
		if(its_filePath == "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat"){
			
			while(getline(datafile,line)){
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> temperature >> urbanTemp;
			
				if((yyyy==old_year) || (old_year ==0)){
					tot_temp += temperature; 
					urbanTot_temp += urbanTemp;
					measurementNo += 1;
					old_year = yyyy;
				}
				
				
				else {
					avgTemp = tot_temp/measurementNo;
					tot_temp= temperature;
					urbanAvgTemp = urbanTot_temp/measurementNo;
					//cout << urbanAvgTemp << endl;
					urbanTot_temp = urbanTemp;
					measurementNo=1;
					yearNumber.push_back(old_year);
					old_year = yyyy;
					yearTemp.push_back(avgTemp);
					urbanYearTemp.push_back(urbanAvgTemp);
				}
			}
			avgTemp = tot_temp/measurementNo;
			urbanAvgTemp = urbanTot_temp/measurementNo;
			yearNumber.push_back(yyyy);
			yearTemp.push_back(avgTemp);
			urbanYearTemp.push_back(urbanAvgTemp);
		}
		
		else{
			
			
			while(getline(datafile,line)){
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> hour >> temperature;
			
				if((yyyy==old_year) || (old_year ==0)){
					tot_temp += temperature; 
					measurementNo += 1;
					old_year = yyyy;
				}
				else {
					avgTemp = tot_temp/measurementNo;
					tot_temp= temperature;
					measurementNo=1;
					yearNumber.push_back(old_year);
					old_year = yyyy;
					yearTemp.push_back(avgTemp);
				}
			}
			avgTemp = tot_temp/measurementNo;
			yearNumber.push_back(yyyy);
			yearTemp.push_back(avgTemp);
			//cout <<old_year <<" " << tot_temp << endl;
			//for (unsigned int i= 0; i<yearTemp.size(); i++){
			//	cout << yearTemp.at(i) << endl;
			//	cout << yearNumber.at(i) << endl;
			//}
			//cout << yearTemp.size() << endl;
			//cout << yearNumber.size() << endl;
	
		}
		datafile.close();
		
		
		for (unsigned int i =0; i <yearTemp.size();i++){
			tot_TempEveryYear += yearTemp.at(i);
			//cout << tot_TempEveryYear << endl;
		}
		meanTempEveryYear = tot_TempEveryYear/yearTemp.size();
		//cout << meanTempEveryYear << endl;
		//cout << yearTemp.size() << endl;
		
		
		// Below, the warmest and coldest years are found and info about them is stored in a vector.
		
		// These are the variables used for the identification.
		float warmestYear, coldestYear, warmestTemp, coldestTemp, newTemp;
		int flag = 0;
		
		for (unsigned int i = 0; i < yearTemp.size(); i++){ // Go through all of the yearTemp vector, created above.
			
			newTemp = yearTemp[i]; // Each time we go through the loop, newTemp stores the element of yearTemp corresponding to the current iteration number.
			
			if (flag == 1){
				if (warmestTemp < newTemp){ // warmestTemp is updated until no other element in yearTemp exceeds it.
					warmestTemp = newTemp;
					warmestYear = yearNumber[i]; // The year corresponding to warmestTemp is also noted
				}
				else if (coldestTemp > newTemp){ // Same as above but for coldest temperature and year.
					coldestTemp = newTemp;
					coldestYear = yearNumber[i];
				}
			}
			
			else if (flag == 0){ // warmest- and coldestTemp are assigned with their first value. This will be updated with the above if-statement. 
				warmestTemp = newTemp;
				coldestTemp = newTemp;
				flag = 1; // flag is set to 1 so that this statement is only entered once.
			}
			
		}
		warmAndCold.push_back(warmestTemp); // Warmest temperature in position [0].
		warmAndCold.push_back(warmestYear); // Year corrseponding to warmestTemp in position [1].
		warmAndCold.push_back(coldestTemp); // Coldest temperature in position [2].
		warmAndCold.push_back(coldestYear); // Year corrseponding to coldestTemp in position [3].
		
	}
	
	
	
	
	
	/*void testFunc(){
		//TGraph* gr = new TGraph(s.datavector.size(), xAxis, yAxis);
		
		TH1D* hist = new TH1D("hPhi", "ROOT func generated v2 distribution; phi; Counts", 
				datavector.size(), 0, datavector.size());
		
		for(unsigned int i = 0 ; i< datavector.size() ; i++){
			hist->SetBinContent(i,datavector.at(i));
		}	
		
		TCanvas* c1 = new TCanvas("c1", "hPhi canvas", 900, 600);
		
		
		
		//gr->GetXaxis()->SetRangeUser(0,s.datavector.size());
		//gr->Draw();
		hist->SetLineColor(35);
		hist->Draw();
		//Lhist->SetLineColor(24);
		//Lhist->Draw("SAME");
		//cout << s.datavector.size() << endl;
	}*/

	
	//This function is used to calculate the average temperature of every day over all years. 
	void tempPerDayExtended(){
		
		//The vectors below are filled with the total temperature of any given day
		//and the number of measurements on that day appears in the entire dataset.
		//The day is counted as the number of days since the start of the year.
		//This means that February 29th appears in the 60th position every four years,
		//and every other day is pushed back, so that the last entry is December 31st every four years. 

		vector <float> sumOfData(366,0), countsOfData(366,0), urbanSumOfData(366,0);
		
		
		for(int k=0; k<366; k++){
			avgOfData.push_back(0);	
			urbanAvgOfData.push_back(0);		
		}
		
		ifstream file("relevantdata.dat");
		string line;
		
		//As this function runs over every year, it handles the change of year in the same
		float temperature, mean_temp, tot_temp = 0, urbanTemp, urbanMean_temp, urbanTot_temp = 0;
		int old_day = 0, old_year=0, measurementNo = 0, start=0, yyyy, mm, dd, hour, old_month=0; 
		cout << "start " << start << endl;
		
		if(its_filePath == "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat"){
		
			while(getline(file,line)){
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> temperature >> urbanTemp;
				
				if(old_day==dd && start==1){
					old_day=dd;
					tot_temp +=temperature; 
					urbanTot_temp += urbanTemp;
					measurementNo+=1;
					
					
				}
				
				else if((old_year+1)==yyyy && start==1){
					
					
					mean_temp=(tot_temp)/measurementNo;
					urbanMean_temp = (urbanTot_temp)/measurementNo;
					sumOfData[::keepTrack(old_year,old_month,old_day)-1]+=mean_temp;
					urbanSumOfData[::keepTrack(old_year,old_month,old_day)-1]+=urbanMean_temp;
					countsOfData[::keepTrack(old_year,old_month, old_day)-1]+=1;	
					
					tot_temp=temperature;
					urbanTot_temp=urbanTemp;
					old_day=dd;
					old_month=mm;
					old_year=yyyy;
					measurementNo=1;
					
					
				}
				
				
				else if(start==0){
					
					old_day=dd;
					old_month=mm;
					old_year=yyyy;
					measurementNo=1;
					tot_temp=temperature;
					urbanTot_temp=urbanTemp;
					cout << "Start " << start << endl;
					//cout << yyyy <<" "<< mm <<" "<< dd <<" "<< hour <<" " << temperature << endl;
					start=1;
				}
				
				else{
					
					mean_temp=(tot_temp)/measurementNo;
					urbanMean_temp = (urbanTot_temp)/measurementNo;
					sumOfData[::keepTrack(old_year,old_month, old_day)-1]+=mean_temp;
					urbanSumOfData[::keepTrack(old_year,old_month,old_day)-1]+=urbanMean_temp;
					countsOfData[::keepTrack(old_year,old_month,old_day)-1]+=1;
					
					tot_temp=temperature;
					urbanTot_temp=urbanTemp;
					old_day=dd;
					old_month=mm;
					measurementNo=1;			
					
				}
			
			}
			
			
			file.close();
		
		}
		
		else{ 
			
			while(getline(file,line)){
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> hour >> temperature;
				
				if(old_day==dd && start==1){
					old_day=dd;
					tot_temp +=temperature;
					measurementNo+=1;
					
					
				}
				
				else if((old_year+1)==yyyy && start==1){
					
					
					mean_temp=(tot_temp)/measurementNo;
					sumOfData[::keepTrack(old_year,old_month,old_day)-1]+=mean_temp;
					countsOfData[::keepTrack(old_year,old_month, old_day)-1]+=1;	
					
					tot_temp=temperature;
					old_day=dd;
					old_month=mm;
					old_year=yyyy;
					measurementNo=1;
					
					
				}
				
				
				else if(start==0){
					
					old_day=dd;
					old_month=mm;
					old_year=yyyy;
					measurementNo=1;
					tot_temp=temperature;
					cout << "Start " << start << endl;
					cout << yyyy <<" "<< mm <<" "<< dd <<" "<< hour <<" " << temperature << endl;
					start=1;
				}
				
				else{
					
					mean_temp=(tot_temp)/measurementNo;
					sumOfData[::keepTrack(old_year,old_month, old_day)-1]+=mean_temp;
					countsOfData[::keepTrack(old_year,old_month,old_day)-1]+=1;
					
					tot_temp=temperature;
					old_day=dd;
					old_month=mm;
					measurementNo=1;			
					
				}
			
			}
			
			
			file.close();
			
		}
		for(int j=0; j<=365; j++){
			avgOfData[j]=(sumOfData[j])/countsOfData[j];
			urbanAvgOfData[j]=(urbanSumOfData[j])/countsOfData[j];
			//cout << avgOfData[j] << endl;
			//cout << urbanAvgOfData[j] << endl;		
		}

		
	}
	
		
	private:
	
	string its_filePath;
}; 

#endif
