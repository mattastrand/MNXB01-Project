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
#include <TGraph.h>

using namespace std;

class tempTrender {
	public:
	tempTrender(string filePath); //Construct using the specified file
	~tempTrender();//Destructor
	
	vector<string> data_from_file; // Will store every meaningful line from the datasets.
	vector <float> datavector,avgOfData;
	
	vector<string> read_temperatures(){
	// Let's read a file and store lines with data in a vector and sort them then store them in a new datafile.
		

		
		float yyyy, mm, dd, hour, min, sec, temperature;
		char d;

		string input, temp, useless_line; // Variables that are used to fill up the vector.
		
		ifstream file(its_filePath.c_str());
		ofstream datafile("relevantdata.dat");
		
		//Skipping the first few lines, which only contain text.
		while(getline(file,useless_line)){
			if (useless_line == "Datum;Tid (UTC);Lufttemperatur;Kvalitet;;Tidsutsnitt:"){
				break;
			}	
		}
		
		float number_of_lines = 0; // In case we want to count the lines in the file.
		
		while(getline(file,temp)){
			// Lines ending with Y (bad recordings) are excluded to begin with.
			input = temp.substr(0,temp.find(";;",0));
			size_t pos = input.find("Y");
			input.erase(0,pos +1);
			
			stringstream data;
			if(input != ""){
				
				//cout << number_of_lines << endl;
				//++number_of_lines; 
				
				data << input;
				data >> yyyy >> d >> mm >> d >> dd >> d >> hour >> d >> min >> d >> sec >> d >> temperature >> d ;
				datafile << yyyy << " " << mm << " " << dd << " " << hour << " " << temperature << endl;				
				data_from_file.push_back(input);
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
		float yyyy, mm, dd, hour, temperature, mean_temp, tot_temp = 0; 
		int old_day = 0, measurementNo = 0; // Don't know what the first day in the file is. Give old_day a "wrong" initial value, then give it the day value read in each new line.
		char d;
		
		while (getline(f, line)){
			// The while loop goes through every line in the datafile. It adds up temperatures until a new day is reached, then takes the mean of these and outputs it in the datavector.
			stringstream data;
			data << line;
			data >> yyyy >> mm >> dd >> hour >> temperature;
			
			cout << yyyy <<" "<< mm <<" "<< dd <<" "<< hour <<" " << temperature << endl;
			if ((yyyy == yearToCalculate) || (yyyy == yearToCalculate + 1)){ // Checking that we are in the right year. year+1 condition is needed for the las day of the year.
				if ((old_day == dd) || (old_day == 0)){ // As long as the day is the same as in the previous line, add the temperature to a temporary total.
					tot_temp += temperature;
					measurementNo += 1;
					old_day = dd;
				}
				else {
					mean_temp = tot_temp / measurementNo; // When the day changes, divide the (temporary) total by the corresponding number of read lines.
					datavector.push_back(mean_temp); // Store the mean in the datavector.
					old_day = dd; 
					measurementNo = 1; // Reset (temporary) temperature total and corresponding number of read lines.
					tot_temp = temperature;
				}
				
			}
			if ( yyyy == yearToCalculate + 1){ // Kill the above process once a new year is reached.
				break;
			}
			f.close();
		}
		
		return datavector;

	} 
	
	//void hotCold(); //Make a histogram of the hottest and coldest day of the year
	//void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year
	
	
	
	
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

	

	void tempPerDayExtended(){
	
		vector <float> sumOfData(366,0), countsOfData(366,0);
		for(int k=0; k<=366; k++){
			avgOfData.push_back(0);			
		}
		
		ifstream file("relevantdata.dat");
		string line;
		
		float temperature, mean_temp, tot_temp = 0;
		int old_day = 0, old_year=0, measurementNo = 0, start=0, dayCount=0, yyyy, mm, dd, hour; 
		cout << "start " << start << endl;
		while(getline(file,line)){
			
			stringstream data;
			data << line;
			data >> yyyy >> mm >> dd >> hour >> temperature;
			//cout << yyyy <<" "<< mm <<" "<< dd <<" "<< hour <<" " << temperature << endl;
			
			if(old_day==dd && start==1){
				old_day=dd;
				tot_temp +=temperature, 
				measurementNo+=1;
				
				
			}
			
			else if(old_year!=yyyy && start==1){
				
				
				mean_temp=(tot_temp)/measurementNo;
				sumOfData[dayCount]+=mean_temp;
				countsOfData[dayCount]+=1;	
				
				tot_temp=temperature;
				old_day=dd;
				old_year=yyyy;
				dayCount=0;
				measurementNo=1;
				
				
			}
			
			else if(start==0){
				
				old_day=dd;
				old_year=yyyy;
				measurementNo=1;
				dayCount=0;
				tot_temp=temperature;
				start=1;
				cout << start << endl;
			}
			
			else{
				
				mean_temp=(tot_temp)/measurementNo;
				sumOfData[dayCount]+=mean_temp;
				countsOfData[dayCount]+=1;
				
				tot_temp=temperature;
				old_day=dd;
				measurementNo=1;
				dayCount+=1;				
				
			}
		
		}
		file.close();
		for(int j=0; j<=365; j++){
			avgOfData[j]=(sumOfData[j])/countsOfData[j];
			cout << avgOfData[j] << endl;	
	
		}

		
		//return avgOfData;
	}
	
		
	private:
	
	string its_filePath;
};

#endif
