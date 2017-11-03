#include <iostream>
#include "tempTrender.h"




tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
	its_filePath = filePath; 

}

tempTrender::~tempTrender(){
}


//void testFunc(){
	//string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	//tempTrender s(pathToFile);
	//s.read_temperatures();
	//s.tempPerDay(1973);

	/*double xAxis[s.datavector.size()], yAxis[s.datavector.size()];
	//for(unsigned int i = 0; i < s.datavector.size(); i++){
		//xAxis[i] = i;
		//yAxis[i] = s.datavector.at(i);
	//}*/

	////TGraph* gr = new TGraph(s.datavector.size(), xAxis, yAxis);
	
	//TH1D* hist = new TH1D("hPhi", "ROOT func generated v2 distribution; phi; Counts", 
			//s.datavector.size(), 0, s.datavector.size());
	
	//for(unsigned int i = 0 ; i< s.datavector.size() ; i++){
		//hist->SetBinContent(i,s.datavector.at(i));
	//}	
	
	//TCanvas* c1 = new TCanvas("c1", "hPhi canvas", 900, 600);
	
	
	/*string path2 = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	//tempTrender Lund(path2);
	//Lund.read_temperatures();
	//Lund.tempPerDay(1973);
	
	
	//TH1D* Lhist = new TH1D("hPhi", "ROOT func generated v2 distribution; phi; Counts", 
			//Lund.datavector.size(), 0, Lund.datavector.size());
	//for (unsigned int i = 0; i < Lund.datavector.size(); i++){
		//Lhist->SetBinContent(i,Lund.datavector.at(i));
	//}*/
	////gr->GetXaxis()->SetRangeUser(0,s.datavector.size());
	////gr->Draw();
	//hist->SetLineColor(35);
	//hist->Draw();
	////Lhist->SetLineColor(24);
	////Lhist->Draw("SAME");
	//cout << s.datavector.size() << endl;
//}

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
	for (unsigned int i= 0; i < t.datavector.size(); i++){
		cout << t.datavector.at(i) << endl;
	}
	//cout << t.datavector.size() << endl;
	t.testFunc();
}
