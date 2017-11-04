#include <iostream>
#include "tempTrender.h"


tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
	its_filePath = filePath; 

}

tempTrender::~tempTrender(){
}


void testFunc(){

	string pathToFile = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	string path2 = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";

	tempTrender s(pathToFile);
	s.read_temperatures();
	//s.tempPerDay(1973);
	s.tempPerDayExtended();
	/*double xAxis[s.datavector.size()], yAxis[s.datavector.size()];
	for(unsigned int i = 0; i < s.datavector.size(); i++){
		xAxis[i] = i;
		yAxis[i] = s.datavector.at(i);
	}*/

	//TGraph* gr = new TGraph(s.datavector.size(), xAxis, yAxis);
	


	TH1D* hist = new TH1D("hPhi", "Söderarm; Day; Temperature", 
			s.avgOfData.size(), 0, s.avgOfData.size());

	
	for(unsigned int i = 0 ; i< s.datavector.size() ; i++){
		hist->SetBinContent(i,s.datavector.at(i));
	}	
	
	TCanvas* c1 = new TCanvas("c1", "hPhi canvas", 900, 600);
	
	
	string path3 = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	tempTrender Lund(path3);
	Lund.read_temperatures();

	//Lund.tempPerDay(1973);
	Lund.tempPerDayExtended();
	
	TH1D* Lhist = new TH1D("hPhi", "Lund; phi; Counts", 
			Lund.avgOfData.size(), 0, Lund.avgOfData.size());
	for (unsigned int i = 0; i < Lund.avgOfData.size(); i++){
		Lhist->SetBinContent(i,Lund.avgOfData.at(i));
	}
	tempTrender Lule(path2);
	Lule.read_temperatures();
	Lule.tempPerDayExtended();
	TH1D* Luhist = new TH1D("hPhi", "Luleå; phi; Counts", 
			Lule.avgOfData.size(), 0, Lule.avgOfData.size());
	for (unsigned int i = 0; i < Lule.avgOfData.size(); i++){
		Luhist->SetBinContent(i,Lule.avgOfData.at(i));
	}

	//gr->GetXaxis()->SetRangeUser(0,s.datavector.size());
	//gr->Draw();
	TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);
	leg->AddEntry(hist, "", "F");
	leg->AddEntry(Luhist, "", "F");
	leg->AddEntry(Lhist, "", "F");
	
	hist->SetLineColor(35);
	hist->SetMinimum(-10);
	hist->SetMaximum(22),
	hist->Draw();
	
	Lhist->SetLineColor(24);
	Lhist->Draw("SAME");
	
	Luhist->SetLineColor(12);
	Luhist->Draw("SAME");
	leg->Draw();
	//cout << s.datavector.size() << endl;
}

int main(){

	string pathToFile = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv"; //Put the path to your data file here

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

}
