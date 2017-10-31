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
	vector<string> read_temperatures(){
		// Let's read a file and store lines with data in a vector.
		string temp;
		vector<string> data_from_file; // Will store every meaningful line from the datasets.
		string input; // Variable that used to fill up the vector.
		ifstream file(its_filePath.c_str());
		while(getline(file,temp)){
			data_from_file.push_back(temp);
		}
		// Now let's reshape the vector and remove meaningless information (lines ending with Y = bad, text)
		data_from_file.erase(data_from_file.begin(), data_from_file.begin() + 12); // Removing first 12 lines, which only include text.
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
