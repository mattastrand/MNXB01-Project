#include <iostream>
#include <tempTrender.h>

//tempTrender::tempTrender(string filePath) {
	
		//its_filePath = filePath; 

//}

//tempTrender::~tempTrender(){
//}

using namespace std;
 
 
 
 void midsummer() {
	 
	string pathToFile = "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender Upp(pathToFile);
	Upp.read_temperatures();
	Upp.tempPerDayExtended();
	
	
	for(unsigned int i=0; i<Upp.midsummer.size();i++){
		
		cout << Upp.midsummer[i] << endl;
	}
	
	
    TH1D*oneDayHist= new TH1D("Gaussian Fit", "MidsummerInUppsala; Temperature; Counts", 60, -10, 30);
    

    
    for(unsigned int j=0; j<Upp.midsummer.size(); j++){
		oneDayHist->Fill(Upp.midsummer[j]);
	
	}
	
	gStyle->SetOptStat(1111);
	TCanvas* c1 = new TCanvas("cl", "Midsummer In Uppsala", 900, 600);
	oneDayHist->SetMinimum(0);
	oneDayHist->SetFillStyle(3001);
	oneDayHist->SetFillColor(kBlue-2);
	oneDayHist->Draw();
	oneDayHist->Fit("gaus");
	
	 
	 
	 
 }	 
	 
