#include <iostream>
#include "tempTrender.h"

tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
	its_filePath = filePath; 

}

tempTrender::~tempTrender(){
}

int main(){
	string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	//string pathToFile;
	//cout << "gimme the file" << endl;
	//cin >> pathToFile;
	tempTrender t(pathToFile);
	t.read_temperatures();
	//for ( int i = 0; i < 30; i++){
	//	cout << t.data_from_file.at(i) << endl;
	//} 
	
	t.tempPerDay(1973);
	cout <<t.datavector.size() << endl;
	for (int i= 0; i < t.datavector.size(); i++){
		cout << t.datavector.at(i) << endl;
	}
}
