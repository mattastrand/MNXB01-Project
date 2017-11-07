#include "tempTrender.h"


 
 void plotMidsummer() { 
	 
	 
	string path = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender MidSummer(path);
	MidSummer.read_temperatures();
	MidSummer.tempPerDayExtended();
	
    TH1D*oneDayHist= new TH1D("Gaussian Fit", "MidsummerInUppsala; Temperature; Counts", 60, 0, 30);
    TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);


    
    for(unsigned int j=0; j<MidSummer.midsummer.size(); j++){
		oneDayHist->Fill(MidSummer.midsummer[j]);
	
	}
	
	gStyle->SetOptStat(1111);
	TCanvas* c1 = new TCanvas("cl", "Midsummer In Uppsala", 1000, 800);
	oneDayHist->SetMinimum(0);
	oneDayHist->SetFillStyle(3001);
	oneDayHist->SetFillColor(kBlue-2);
	oneDayHist->Draw();
	oneDayHist->Fit("gaus");
	leg->AddEntry("gauss");
	leg->Draw("SAME");
	 
 }	 
	 
