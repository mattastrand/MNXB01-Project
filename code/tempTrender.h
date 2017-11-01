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
	
	vector<string> data_from_file; 		 // Will store every meaningful line from the datasets.
	
	vector<string> read_temperatures(){
	// Let's read a file and store lines with data in a vector.
		
		string temp;
		string input; // Variable that used to fill up the vector.
		
		ifstream file(its_filePath.c_str());
		
		while(getline(file,temp)){
			// Lines ending with Y (bad recordings) are excluded to begin with.
			input = temp.substr(0,temp.find(";;",0));
			size_t pos = input.find("Y");
			input.erase(0,pos +1);
			if (input != ""){
				data_from_file.push_back(input);
			}
		}
		// Now let's reshape the vector and remove the first few lines, which only include text.
		data_from_file.erase(data_from_file.begin(), data_from_file.begin() + 8); 
		//data_from_file.erase(remove(data_from_file.begin(), data_from_file.end(), 'Y'), data_from_file.end());
		//cout << data_from_file[11] << endl; // Checking that the above works.
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
