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
	
	//Define the canvas and legend to be used
	TCanvas* c1 = new TCanvas("c1", "hPhi canvas", 900, 600);
	TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);
	
	//Below is how the histogram for any dataset is constructed. 
	
	
	string pathSoder = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	tempTrender Soder(pathSoder);
	Soder.read_temperatures();
	//soder.tempPerDay(1973);
	Soder.tempPerDayExtended();

	TH1D* SoderHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
			Soder.avgOfData.size(), 0, Soder.avgOfData.size());
	
	for(unsigned int i = 0 ; i< Soder.avgOfData.size() ; i++){
		SoderHist->SetBinContent(i,Soder.avgOfData.at(i));

	

	}	
	
	leg->AddEntry(SoderHist, "", "F");
	SoderHist->SetLineColor(35);
	SoderHist->SetMinimum(-15);
	SoderHist->SetMaximum(22),
	SoderHist->Draw();
	
	
	

	string pathLund = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	tempTrender Lund(pathLund);

	Lund.read_temperatures();

	//Lund.tempPerDay(1973);
	Lund.tempPerDayExtended();
	
	TH1D* LundHist = new TH1D("hPhi", "Lund; phi; Counts", 
			Lund.avgOfData.size(), 0, Lund.avgOfData.size());
	
	for (unsigned int i = 0; i < Lund.avgOfData.size(); i++){
		LundHist->SetBinContent(i,Lund.avgOfData.at(i));
	}
	
	leg->AddEntry(LundHist, "", "F");
	LundHist->SetLineColor(24);
	LundHist->Draw("SAME");
	
	
	
	string pathLule = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	tempTrender Lule(pathLule);
	Lule.read_temperatures();
	Lule.tempPerDayExtended();
	
	TH1D* LuleHist = new TH1D("hPhi", "Lulea; phi; Counts", 
			Lule.avgOfData.size(), 0, Lule.avgOfData.size());
	
	for (unsigned int i = 0; i < Lule.avgOfData.size(); i++){
		LuleHist->SetBinContent(i,Lule.avgOfData.at(i));
	}
		
	leg->AddEntry(LuleHist, "", "F");
	LuleHist->SetLineColor(12);
	LuleHist->Draw("SAME");
	
	
	
	leg->Draw();
}

int main(){
	/*
	string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv"; //Put the path to your data file here

	tempTrender t(pathToFile);
	t.read_temperatures();
	
	t.tempPerDay(1973);
	t.tempPerDayExtended();
	*/
}
