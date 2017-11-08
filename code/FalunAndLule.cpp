#include <iostream>
#include "tempTrender.h"

tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
	its_filePath = filePath; 

}

tempTrender::~tempTrender(){
}


void plotFalunAndLule(){
	
	TCanvas* c1 = new TCanvas("c1", "Comparing warm and cold years - canvas", 1600, 1200);
	TLegend *leg1 = new TLegend(0.50,0.5,0.75, 0.3);
	TLegend *leg2 = new TLegend(0.50,0.5,0.75, 0.3);
	c1->Divide(2,1);
	
	string pathFalun = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falun.csv";
	tempTrender Falun(pathFalun);
	
	Falun.read_temperatures();
	Falun.tempEveryYear();
	
	Falun.tempPerDay(Falun.warmAndCold[1]);
	TH1D* FalunWarmHist = new TH1D("hPhi", "Falun; Day; Temperature (#circ C)", 
			Falun.datavector.size() -1, 0, Falun.datavector.size());
	
	for(unsigned int i = 0 ; i< Falun.datavector.size() ; i++){
		FalunWarmHist->SetBinContent(i,Falun.datavector.at(i));
	}
	
	FalunWarmHist->SetLineColor(kOrange +7);
	FalunWarmHist->SetMinimum(-5);
	FalunWarmHist->SetMaximum(30);
	c1->cd(1);
	FalunWarmHist->Draw();
	
	leg1->AddEntry(FalunWarmHist, "Temperature measurements in Falun, 1955");
	c1->cd(1);
	leg1->Draw("SAME");
	
	

	string pathLule = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	tempTrender Lule(pathLule);
	
	Lule.read_temperatures();
	Lule.tempEveryYear();

	Lule.tempPerDay(Lule.warmAndCold[1]);
	TH1D* LuleWarmHist = new TH1D("hPhi", "Lulea; Day; Temperature (#circ C)", 
			Lule.datavector.size() -1, 0, Lule.datavector.size());
	
	for(unsigned int i = 0 ; i< Lule.datavector.size() ; i++){
		LuleWarmHist->SetBinContent(i,Lule.datavector.at(i));
	}

	LuleWarmHist->SetLineColor(kCyan +2);
	LuleWarmHist->SetMinimum(-5);
	LuleWarmHist->SetMaximum(30);
	c1->cd(2);
	LuleWarmHist->Draw("SAME");
	
	leg2->AddEntry(LuleWarmHist, "Temperature measurements in Lulea, 1960");
	c1->cd(2);
	leg2->Draw("SAME");
	
}
