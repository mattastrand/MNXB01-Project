#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class tempTrender {
	public:
	tempTrender(string filePath); //Construct using the specified file
	~tempTrender();//Destructor
	
	vector<string> data_from_file; // Will store every meaningful line from the datasets.
	vector <float> datavector;
	
	vector<string> read_temperatures(){
	// Let's read a file and store lines with data in a vector and sort them then store them in a new datafile.
		
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
		float yyyy, mm, dd, hour, min, sec, temperature;
		char d;
		
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
		ifstream f("relevantdata.dat");
		string line;
		
		float yyyy, mm, dd, hour, temperature, mean_temp, tot_temp = 0;
		int old_day = 0 , measurementNo = 0;
		char d;
		
		while (getline(f, line)){
			stringstream data;
			data << line;
			data >> yyyy >> mm >> dd >> hour >> temperature;
			if ((yyyy == yearToCalculate) || (yyyy == yearToCalculate + 1)){
				if ((old_day == dd) || (old_day == 0)){
					tot_temp += temperature;
					measurementNo += 1;
					old_day = dd;
				}
				else {
					mean_temp = tot_temp / measurementNo;
					datavector.push_back(mean_temp);
					old_day = dd;
					measurementNo = 1;
					tot_temp = temperature;
				}
				
			}
			if ( yyyy == yearToCalculate + 1){
				break;
			}
		}
		
		return datavector;

	} 
	
	//void hotCold(); //Make a histogram of the hottest and coldest day of the year
	//void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
	string its_filePath;
};

#endif
