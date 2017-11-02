#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class tempTrender {
	public:
	tempTrender(string filePath); //Construct using the specified file
	~tempTrender();//Destructor
	
	
	vector<string> data_from_file; 		 // Will store every meaningful line from the datasets.
	
	vector<string> read_temperatures(){
	// Let's read a file and store lines with data in a vector.
		
		string input, temp, line; // Variable that used to fill up the vector.
		
		ifstream file(its_filePath.c_str());
		ofstream datafile("relevantdata.dat");
		while(getline(file,line)){
			if (line == "Datum;Tid (UTC);Lufttemperatur;Kvalitet;;Tidsutsnitt:"){
				break;
			}	
		}
		
		while(getline(file,temp)){
			// Lines ending with Y (bad recordings) are excluded to begin with.
			input = temp.substr(0,temp.find(";;",0));
			size_t pos = input.find("Y");
			input.erase(0,pos +1);
			
			
			float yyyy, mm, dd, hour, min, sec, temperature;
			char d;
			//char key[] = "G";
			//char buffer[1];
			//char *var1 = "G";
			//char e;
			//cout << e << endl;
			if(input != ""){
				stringstream data;
				data << input;
				data >> yyyy >> d >> mm >> d >> dd >> d >> hour >> d >> min >> d >> sec >> d >> temperature >> d ;
				datafile << yyyy << " " << mm << " " << dd << " " << hour << " " << temperature << endl;
			}
			if (input != ""){
				data_from_file.push_back(input);
			}
		
		}
		datafile.close();
		// Now let's reshape the vector and remove meaningless information (lines ending with Y = bad, text)
		//data_from_file.erase(data_from_file.begin(), data_from_file.begin() + 12); // Removing first 12 lines, which only include text.
		
		
		return data_from_file;
		
		
		
	}
	
	//void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	//void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	//void tempPerDay(); //Make a histogram of the average temperature of each day of the year
	//void hotCold(); //Make a histogram of the hottest and coldest day of the year
	//void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
	string its_filePath;
};

#endif
