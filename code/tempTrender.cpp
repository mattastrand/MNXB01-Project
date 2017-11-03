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
	string pathToFile = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-openda_Karlstad.csv"; //Put the path to your data file here
	tempTrender t(pathToFile);
	t.read_temperatures();
	for ( int i = 0; i < 30; i++){
		cout << t.data_from_file.at(i) << endl;
	} 
	
}
