/* Required header: tempTrender.h 
 * 
 * Purpose: plot the values from the "midsummer" vector to a histogram and fit a Gaussian to the result  
 * 
 * Included functions: void plotMidsummer() 
 * 
 */

#include "tempTrender.h"


 
 void plotMidsummer() { 
	 
	 // Call the neseccary functions found in the included header file concerning a specific data set.
	string path = "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender MidSummer(path);
	MidSummer.read_temperatures();
	MidSummer.tempPerDayExtended();
	
	//Creates histogram
    TH1D*oneDayHist= new TH1D("Gaussian Fit", "Winter solstice Uppsala; Temperature (#circ C); Counts", 80, -25, 15);
    //TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);


    //Fill the histogram with the values from the " midsummer" vector
    for(unsigned int j=0; j<MidSummer.midsummer.size(); j++){
		oneDayHist->Fill(MidSummer.midsummer[j]);
	
	}
	
	//Plotting the histogram
	gStyle->SetOptStat(1111);
	TCanvas* c1 = new TCanvas("cl", "Winter solstice Uppsala", 1000, 800);
	oneDayHist->SetMinimum(0);
	oneDayHist->SetFillStyle(3001);
	oneDayHist->SetFillColor(kBlue-2);
	oneDayHist->Draw();
	//Fitting a gaussian to the obtained result
	oneDayHist->Fit("gaus");
	oneDayHist->FitPanel();
	//leg->AddEntry("gaus");
	//leg->Draw("SAME");
	 
 }	 
	 
