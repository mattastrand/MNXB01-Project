/* Class: tempTrender 
 * 
 * Purpose: Mainly extract the relevant data out of a given datasets and return parts of interest in the relevant data.
 * 
 * Included functions: 
 * vector <string> read_temperatures()
 * vector <float> tempPerDay(int yearToCalculate)
 * void tempEveryYear()
 * void tempPerDayExtended()
 * 
 * Private varible(s): 
 * string its_filePath
 * 
 * Public varible(s): 
 * vector <float> datavector,urbanDatavector,avgOfData, urbanAvgOfData
 * yearTemp, urbanYearTemp, yearNumber, midsummer,urbanMidsummer
 * warmAndCold,theWarmestDays,theColdestDays,theWarmestUrbanDays,theColdestUrbanDays;
 * float meanTempEveryYear;
 * 
 */


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
#include <TLatex.h>
#include <TAttFill.h>
#include "keepTrack.cpp"

using namespace std;

class tempTrender {
	public:
	tempTrender(string filePath); //Construct using the specified file
	~tempTrender();//Destructor
	
	
	
	/* Explanaition of the public varibles
	 * 
	 * 
	 * vector <string> data_from_file: used to handle the read line from the data files in a way to select information.
	 * 
	 * vector <float> 
	 * - datavector: used to store all the mean temperature of a day for every day in a specific year.
	 * - urbanDatavector: same as "datavector" but for the urban mean temperature.
	 * - avgOfData:  used to store the average temperature of specific day over the whole dataset for all days in the year. 
	 * - urbanAvgOfData: same as "avgOfData" but for the urban temperature.
	 * - yearTemp: used to store the averagetemperature of a whole year.
	 * - urbanYearTemp: same as "yearTemp" but for the urban temperature.
	 * - yearNumber: used to store the corresponding year to the average temp stored in "yearTemp"
	 * - midsummer: used to store all temperatures for a specific day of interest, here used for midsummer.
	 * - urbanMidsummer: same as "midsummer" but for the urban temperature.
	 * - warmAndCold: 
	 * - theWarmestDays: used to store the warmest measured temperature for a specific day in a year, for all days in the year. 
	 * - theColdestDays: same as "theWarmestDays" but for the coldest measured temperature.
	 * - theWarmestUrbanDays: same as "theWarmestDays" but for urban temperature.
	 * - theColdestUrbanDays: same as "theColdestDays" but for urban temperature.
	 * 
	 * float meanTempEveryYear: used to store the calculated mean temp over the whole year of interest.
	 *  
	 * */
	 
	vector <string> data_from_file; // Will store every meaningful line from the datasets.
	vector <float> datavector,urbanDatavector,avgOfData, urbanAvgOfData;
	vector <float> yearTemp, urbanYearTemp, yearNumber, midsummer,urbanMidsummer;
	vector <float> warmAndCold,theWarmestDays,theColdestDays,theWarmestUrbanDays,theColdestUrbanDays;
	float meanTempEveryYear;
	
	
	
	
	/* Function description
	 * 
	 * Name: vector<string> read_temperatures()
	 * Purpose: Read the raw data files and write the relevant data into a new file in a convenient format.
	 * Arguments(s): needs a raw data file 
	 * Returns: a file called "relevantdata.dat", containing the relevant data. 
	 * 
	 */
	 
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
			
			//Reading the file with raw data and print the relevant result to the relevant data file.
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
			
			//Reading the file with raw data and print the relevant result to the relevant data file.
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
	
	
	
	
	
	/* Function description
	 * 
	 * Name: vector <float> tempPerDay(int yearToCalculate)
	 * Purpose: Calculates the average temperature for each day during a specific year.
	 * Arguments(s): The specific year of interest and a relevant data set.
	 * Returns: returns "datavector" and "urbanDatavector" containing the average temperatures and urban average temperatures for all days during the year of interest.
	 * 
	 */
	 
	vector <float> tempPerDay(int yearToCalculate){
		// This function takes a year as input and computes the average temperature of each day in that year.
		
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
			
			// The while loop goes through every line in the datafile. It adds up temperatures until a new day is reached, then takes the mean of these and outputs it in the datavector.
			while (getline(f, line)){
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> temperature >> urbanTemp;
			
				// Checking that we are in the right year. year+1 condition is needed for the las day of the year.
				if ((yyyy == yearToCalculate) || (yyyy == yearToCalculate + 1)){ 
					
					// As long as the day is the same as in the previous line, add the temperature to a temporary total.
					if ((old_day == dd) || (old_day == 0)){ 
						tot_temp += temperature;
						urbanTot_temp += urbanTemp;
						measurementNo += 1;
						old_day = dd;
						old_month = mm;
					}
					
					// When the day changes, divide the (temporary) total by the corresponding number of read lines.
					else {
						mean_temp = tot_temp / measurementNo; 
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
				
				// Kill the above process once a new year is reached.
				if ( yyyy == yearToCalculate + 1){ 
					break;
				}
					
			}
		}
		
		else{
			
			// The while loop goes through every line in the datafile. It adds up temperatures until a new day is reached, then takes the mean of these and outputs it in the datavector.
			while (getline(f, line)){
				
				
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> hour >> temperature;
				
				// Checking that we are in the right year. year+1 condition is needed for the las day of the year.
				if ((yyyy == yearToCalculate) || (yyyy == yearToCalculate + 1)){ 
					
					// As long as the day is the same as in the previous line, add the temperature to a temporary total.
					if ((old_day == dd) || (old_day == 0)){ 
						tot_temp += temperature;
						measurementNo += 1;
						old_day = dd;
						old_month = mm;
					}
					
					// When the day changes, divide the (temporary) total by the corresponding number of read lines.
					else {
						mean_temp = tot_temp / measurementNo; 
						datavector[::keepTrack(yearToCalculate, old_month,old_day) -1]=mean_temp; // Store the mean in the datavector.
						old_day = dd; 
						old_month = mm;
						measurementNo = 1; // Reset (temporary) temperature total and corresponding number of read lines.
						tot_temp = temperature;
					}
					
				}
				
				// Kill the above process once a new year is reached.
				if ( yyyy == yearToCalculate + 1){ 
					break;
				}
				
			}	
			f.close();
		}
		return datavector, urbanDatavector;

	}
	
	
	
	
	/* Function description
	 * 
	 * Name: void tempEveryYear()
	 * Purpose: Calculates the average temperature for all days during a specific year..
	 * Argument(s): needs a relervant data set.
	 * Returns: the vector "warmAndCold" containing the warmest year and corresponding temperature, the coldest year and the corresponding temperature.
	 * 
	 */
	
	void tempEveryYear(){
		
		
		ifstream datafile("relevantdata.dat");
		string line;
		
		// Variables used to fill a datavector (in turn used to produce the histogram) with mean temperatures corresponding to each day in the chosen year.
		float temperature, urbanTemp, avgTemp, urbanAvgTemp, tot_temp = 0, urbanTot_temp = 0;
		int yyyy, mm, dd, hour, measurementNo = 0, old_year=0;
		float tot_TempEveryYear = 0;
		meanTempEveryYear = 0;
		if(its_filePath == "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat"){
			
			//Read the data file and extract information of interest for the case when we look at the uppsala data set.
			while(getline(datafile,line)){
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> temperature >> urbanTemp;
				
				
				//Check if a new year is reached, otherwise the temperature is added on top of the previous sum of temperatures.
				if((yyyy==old_year) || (old_year ==0)){
					tot_temp += temperature; 
					urbanTot_temp += urbanTemp;
					measurementNo += 1;
					old_year = yyyy;
				}
				
				//When a new year is reached we calculate the average of the previous year and reset the counting.
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
			//An extra block to deal with the last year in the dataset which is not automatically dealt with in the code above.
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
		
		// Go through all of the yearTemp vector, created above. Exclude year 2015 as it might have incomplete data.
		for (unsigned int i = 0; i < yearTemp.size()-1; i++){ 

			newTemp = yearTemp[i]; // Each time we go through the loop, newTemp stores the element of yearTemp corresponding to the current iteration number.
			
			if (flag == 1){
				if (warmestTemp < newTemp){ // warmestTemp is updated until no other element in yearTemp exceeds it.
					warmestTemp = newTemp;
					warmestYear = yearNumber[i]; // The year corresponding to warmestTemp is also noted
				}
				// Same as above but for coldest temperature and year.
				else if (coldestTemp > newTemp){ 
					coldestTemp = newTemp;
					coldestYear = yearNumber[i];
				}
			}
			
			// warmest- and coldestTemp are assigned with their first value. This will be updated with the above if-statement. 
			else if (flag == 0){ 
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
	
	
	
	/* Function description
	 * 
	 * Name: void tempPerDayExtended()
	 * Purpose: Calculates the average temperature for every day in the year, based on all years in the datset. 
	 * 			Finds the maximum and minimum average temperature for a specific day recorded over the whole dataset.
	 * 			Finds the maximum and minimum average urban temperature for a specific day recorded over the whole dataset.
	 * 			Store all average temperatures for a specific day of interest over the whole data set.
	 * Argument: needs a relervant data set.
	 * Returns: the vectors- avgOfData, urbanAvgOfData, theWarmestDays, theColdestDays, theWarmestUrbanDays, theColdestUrbanDays and midsummer. 
	 * 
	 */
	void tempPerDayExtended(){
		
		//The vectors below are filled with the total temperature of any given day
		//and the number of measurements on that day appears in the entire dataset.
		//The day is counted as the number of days since the start of the year.
		//This means that Febru<<ary 29th appears in the 60th position every four years,
		//and every other day is pushed back, so that the last entry is December 31st every four years. 

		vector <float> sumOfData(366,0), countsOfData(366,0), urbanSumOfData(366,0);
		
		//Setting the lenght of the needed vectors to the wanted size. 
		for(int k=0; k<366; k++){
			avgOfData.push_back(0);	
			urbanAvgOfData.push_back(0);
			theWarmestDays.push_back(-200);
			theColdestDays.push_back(200);
			theWarmestUrbanDays.push_back(-200);
			theColdestUrbanDays.push_back(200);		
		}
		
		ifstream file("relevantdata.dat");
		string line;
		
		//Declaring necessary variables used to extract the data from the relvant data file.
		float temperature, mean_temp, tot_temp = 0, urbanTemp, urbanMean_temp, urbanTot_temp = 0;
		int old_day = 0, old_year=0, measurementNo = 0, start=0, yyyy, mm, dd, hour, old_month=0, theDay=356; 
		
		//Special code section for the case we read data from uppsala.
		if(its_filePath == "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat"){
			
			//Reading through the data for the uppsala dataset 
			while(getline(file,line)){
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> temperature >> urbanTemp;
				
				//Checking if the data read is still within the the same day as before.
				if(old_day==dd && start==1){
					old_day=dd;
					tot_temp +=temperature; 
					urbanTot_temp += urbanTemp;
					measurementNo+=1;
					
					
				}
				
				//If a new year is reached values of interest is computed for the previous day and counting varibles are reset.
				else if((old_year+1)==yyyy && start==1){
					
					
					mean_temp=(tot_temp)/measurementNo;
					urbanMean_temp = (urbanTot_temp)/measurementNo;
					
					//Checking for a potential new warmest day  
					if(mean_temp>theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
												
					}
					//Checking for a potential new coldest day 
					else if(mean_temp<theColdestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theColdestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
						
					}
					//Checking for a potential new warmest urban day 
					if(urbanMean_temp>theWarmestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theWarmestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]=urbanMean_temp;
						
					}
					//Checking for a potential new coldest urban day 
					else if(urbanMean_temp<theColdestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theColdestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]=urbanMean_temp;
						
					}
					
					//If the specific day of interest is computed we add the new value to the midsummer vector. 
					if(::keepTrack(old_year,old_month,old_day)==theDay){
						midsummer.push_back(mean_temp);
						urbanMidsummer.push_back(urbanMean_temp);;
					}
					
					//Adding the computed mean and urban mean temp to the corresponding vector positions
					sumOfData[::keepTrack(old_year,old_month,old_day)-1]+=mean_temp;
					urbanSumOfData[::keepTrack(old_year,old_month,old_day)-1]+=urbanMean_temp;
					countsOfData[::keepTrack(old_year,old_month, old_day)-1]+=1;	
					
					//Reset the counters and help varibles for a new day
					tot_temp=temperature;
					urbanTot_temp=urbanTemp;
					old_day=dd;
					old_month=mm;
					old_year=yyyy;
					measurementNo=1;
					
					
				}
				
				//Statement activated just ones during the while-loop to get started reading correctly.
				else if(start==0){
					
					old_day=dd;
					old_month=mm;
					old_year=yyyy;
					measurementNo=1;
					tot_temp=temperature;
					urbanTot_temp=urbanTemp;
					start=1;
				}
				
				//If we reached a new day we compute and save the things of interest.
				else{
					
					mean_temp=(tot_temp)/measurementNo;
					urbanMean_temp = (urbanTot_temp)/measurementNo;
					
					//Checking for a potential new warmest day  
					if(mean_temp>theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
												
					}
					
					//Checking for a potential new coldest day 
					else if(mean_temp<theColdestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theColdestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
						
					}
					
					//Checking for a potential new warmest urban day 
					if(urbanMean_temp>theWarmestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theWarmestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]=urbanMean_temp;
						
					}
					
					//Checking for a potential new coldest urban day 
					else if(urbanMean_temp<theColdestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theColdestUrbanDays[::keepTrack(old_year,old_month,old_day)-1]=urbanMean_temp;
						
					}
					
					//If the specific day of interest is computed we add the new value to the midsummer vector. 
					if(::keepTrack(old_year,old_month,old_day)==theDay){
						midsummer.push_back(mean_temp);
						urbanMidsummer.push_back(urbanMean_temp);;
					}
					
					//Adding the computed mean and urban mean temp to the corresponding vector positions
					sumOfData[::keepTrack(old_year,old_month, old_day)-1]+=mean_temp;
					urbanSumOfData[::keepTrack(old_year,old_month,old_day)-1]+=urbanMean_temp;
					countsOfData[::keepTrack(old_year,old_month,old_day)-1]+=1;
					
					//Reset the counters and help varibles for a new day
					tot_temp=temperature;
					urbanTot_temp=urbanTemp;
					old_day=dd;
					old_month=mm;
					measurementNo=1;			
					
				}
			
			}
			
			
			file.close();
		
		}
		
		
		//Code to read all data sets except for the one from uppsala 
		else{ 
			
			//Loop to read through the relevant data file and extract information of interest
			while(getline(file,line)){
				
				stringstream data;
				data << line;
				data >> yyyy >> mm >> dd >> hour >> temperature;
				
				//Checking if the data read is still within the the same day as before.
				if(old_day==dd && start==1){
					old_day=dd;
					tot_temp +=temperature;
					measurementNo+=1;
					
					
				}
				
				//If a new year is reached values of interest is computed for the previous day and counting varibles are reset.
				else if((old_year+1)==yyyy && start==1){
					
					
					mean_temp=(tot_temp)/measurementNo;
					
					//Checking for a potential new warmest day  
					if(mean_temp>theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
												
					}
					
					//Checking for a potential new coldest day 
					else if(mean_temp<theColdestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theColdestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
						
					}
					
					//If the specific day of interest is computed we add the new value to the midsummer vector.
					if(::keepTrack(old_year,old_month,old_day)==theDay){
						midsummer.push_back(mean_temp);
					}
					sumOfData[::keepTrack(old_year,old_month,old_day)-1]+=mean_temp;
					countsOfData[::keepTrack(old_year,old_month, old_day)-1]+=1;	
					
					tot_temp=temperature;
					old_day=dd;
					old_month=mm;
					old_year=yyyy;
					measurementNo=1;
					
					
				}
				
				
				//Statement activated just ones during the while-loop to get started reading correctly.
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
					
					//Checking for a potential new warmest day  
					if(mean_temp>theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theWarmestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
												
					}
					
					//Checking for a potential new coldest day 
					else if(mean_temp<theColdestDays[::keepTrack(old_year,old_month,old_day)-1]){
						
						theColdestDays[::keepTrack(old_year,old_month,old_day)-1]=mean_temp;
						
					}
					
					//If the specific day of interest is computed we add the new value to the midsummer vector. 
					if(::keepTrack(old_year,old_month,old_day)==theDay){
						midsummer.push_back(mean_temp);
					}
					
					//Adding the computed mean temperature to the coresponding vector position
					sumOfData[::keepTrack(old_year,old_month, old_day)-1]+=mean_temp;
					countsOfData[::keepTrack(old_year,old_month,old_day)-1]+=1;
					
					//Reset the counters and help varibles for a new day
					tot_temp=temperature;
					old_day=dd;
					old_month=mm;
					measurementNo=1;			
					
				}
			
			}
			
			
			file.close();
			
		}
		
		//for(int j=0; j<=365; j++){
			//avgOfData[j]=(sumOfData[j])/countsOfData[j];
			//urbanAvgOfData[j]=(urbanSumOfData[j])/countsOfData[j];
			//cout <<theWarmestDays[j] << endl;
			//cout << avgOfData[j] << endl;
			//cout <<theColdestDays[j]<< endl;
			//cout <<theWarmestUrbanDays[j]<< endl;
			//cout << urbanAvgOfData[j] << endl;
			//cout <<theColdestUrbanDays[j]<< endl;		
			
		
		//}

		
	}
	
	/* Explanaition of the private varible(s)
	 *  
	 * string its_filePath: used acces the file of data that should be read.
	 * 
	 */	
	private:
	
	string its_filePath;
}; 

#endif
