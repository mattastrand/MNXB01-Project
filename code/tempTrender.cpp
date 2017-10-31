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
	string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv"; //Put the path to your data file here
	//ifstream file (pathToFile);
	tempTrender t(pathToFile);
	t.read_temperatures();
}
