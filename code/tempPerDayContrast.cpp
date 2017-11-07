#include <iostream>
#include "tempTrender.h"

void plotComparison() {
	
	string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender Upp(pathToFile);
	Upp.read_temperatures();
	Upp.tempPerDayExtended();
	
	
	TH1D* UppHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);
	
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppHist->SetBinContent(i,Upp.avgOfData.at(i));
	}
	
	
	TH1D* UppWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppWarmHist->SetBinContent(i,Upp.theWarmestDays.at(i));
	}
	
	TH1D* UppColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppColdHist->SetBinContent(i,Upp.theColdestDays.at(i));
	}
	

	UppHist->SetLineColor(kGreen +1);
	UppHist->SetMinimum(-35);
	UppHist->SetMaximum(30),
	UppHist->Draw();
	UppColdHist->SetLineColor(kBlue);
	UppWarmHist->SetLineColor(kRed);
	UppColdHist->Draw("SAME");
	UppWarmHist->Draw("SAME");
	
	leg->AddEntry(UppWarmHist, "Highest recorded temperature");
	leg->AddEntry(UppHist, "Average of recorded temperatures");
	leg->AddEntry(UppColdHist, "Lowest recorded temperature");
	leg->Draw("SAME");
	
}
