#include <iostream>
#include "tempTrender.h"


tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
	its_filePath = filePath; 

}

tempTrender::~tempTrender(){
}

double Gaussian (double* x, double* par){
	return par[0]*exp(-0.5*(x[0]*x[0] - 2*x[0]*par[1] + par[1]*par[1]) /(par[2]*par[2]));
}


void plotTempExtended(){
	
	//Define the canvas and legend to be used
	TCanvas* c1 = new TCanvas("c1", "hPhi canvas", 1400, 900);
	TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);
	
	
	//TF1* func = new TF1("Gaussian", Gaussian, 1, 366,3);
	//func->SetParameters(10,100,75);
	
	//Below is how the histogram for any dataset is constructed. 
	//The histograms are pretty neatly set up at the moment.
	//To use them, just uncomment relevant lines, and make sure that they are all drawn 
	// to the same canvas.
	
	
	
	
	string pathSoder = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	tempTrender Soder(pathSoder);
	Soder.read_temperatures();
	
	
	
	Soder.tempPerDayExtended();

	TH1D* SoderHist = new TH1D("hPhi", "Soderarm; Day; Temperature (#circ C)", 
			Soder.avgOfData.size()-1 , 0, Soder.avgOfData.size() );
	
	for(unsigned int i = 0 ; i< Soder.avgOfData.size() ; i++){
		SoderHist->SetBinContent(i,Soder.avgOfData.at(i));
	}
	
	
	//SoderHist->Fit(func,"QOR");
	
	leg->AddEntry(SoderHist, "","L");
	
	SoderHist->SetLineColor(kRed);
	SoderHist->SetMinimum(-15);
	SoderHist->SetMaximum(24);
	SoderHist->Draw();
	
	
	
	
	
	string pathUpp = "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender Upp(pathUpp);
	
	Upp.read_temperatures();
	
	Upp.tempPerDayExtended();
	
	TH1D* UppHist = new TH1D ("hPhi", "Uppsala; Day; Temperature (#circ C)", 
			Upp.avgOfData.size()-1 , 0, Upp.avgOfData.size());
			
	for(unsigned int i = 0 ; i< Upp.avgOfData.size() ; i++){
		UppHist->SetBinContent(i,Upp.avgOfData.at(i));
	}

	UppHist->SetLineColor(kMagenta);
	UppHist->SetMinimum(-20);
	UppHist->SetMaximum(30),
	UppHist->Draw("SAME");
	
	TH1D* UrbanUppHist = new TH1D ("hPhi", "Uppsala Urban; Day; Temperature (#circ C)", 
			Upp.urbanAvgOfData.size() -1, 0, Upp.urbanAvgOfData.size());
			
	for(unsigned int i = 0 ; i< Upp.urbanAvgOfData.size() ; i++){
		UrbanUppHist->SetBinContent(i,Upp.urbanAvgOfData.at(i));
	}

	
	leg->AddEntry(UppHist, "", "L");
	leg->AddEntry(UrbanUppHist, "", "L");
	UrbanUppHist->SetLineColor(kMagenta +3);
	UrbanUppHist->Draw("SAME");
	
	
	
	
	
	
	
	string pathLund = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	tempTrender Lund(pathLund);

	Lund.read_temperatures();

	
	
	Lund.tempPerDayExtended();
	
	TH1D* LundHist = new TH1D("hPhi", "Lund; day; Temperature (#circ C)", 
			Lund.avgOfData.size() -1, 0, Lund.avgOfData.size());
	
	for (unsigned int i = 0; i < Lund.avgOfData.size(); i++){
		LundHist->SetBinContent(i,Lund.avgOfData.at(i));
	}
	
	leg->AddEntry(LundHist, "", "L");
	LundHist->SetLineColor(kBlue);
	LundHist->Draw("SAME");
	
	
	
	
	
	
	string pathLule = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	tempTrender Lule(pathLule);
	Lule.read_temperatures();

	
	
	Lule.tempPerDayExtended();
	
	TH1D* LuleHist = new TH1D("hPhi", "Lulea; day; Temperature (#circ C)", 
			Lule.avgOfData.size() -1, 0, Lule.avgOfData.size());
	
	for (unsigned int i = 0; i < Lule.avgOfData.size(); i++){
		LuleHist->SetBinContent(i,Lule.avgOfData.at(i));
	}
		
	leg->AddEntry(LuleHist, "", "L");
	LuleHist->SetLineColor(kCyan);
	LuleHist->Draw("SAME");
	
	
	
	
	string pathBoras = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Boras.csv";
	tempTrender Boras(pathBoras);
	Boras.read_temperatures();
	
	Boras.tempPerDayExtended();
	
	TH1D* BorasHist = new TH1D("hPhi", "Boras; day; Temperature (#circ C)", 
			Boras.avgOfData.size() -1, 0, Boras.avgOfData.size());
	
	for (unsigned int i = 0; i < Boras.avgOfData.size(); i++){
		BorasHist->SetBinContent(i,Boras.avgOfData.at(i));
	}
		
	leg->AddEntry(BorasHist, "", "L");
	BorasHist->SetLineColor(kGreen);
	BorasHist->Draw("SAME");
	
	
	string pathFalun = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Falun.csv";
	tempTrender Falun(pathFalun);
	Falun.read_temperatures();
	
	
	Falun.tempPerDayExtended();
	
	TH1D* FalunHist = new TH1D("hPhi", "Falun; day; Temperature (#circ C)", 
			Falun.avgOfData.size() -1, 0, Falun.avgOfData.size());
	
	for (unsigned int i = 0; i < Falun.avgOfData.size(); i++){
		FalunHist->SetBinContent(i,Falun.avgOfData.at(i));
	}
		
	leg->AddEntry(FalunHist, "", "L");
	FalunHist->SetLineColor(kGreen +2);
	FalunHist->Draw("SAME");
	
	
	
	
	string pathFalster = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Falsterbo.csv";
	tempTrender Falster(pathFalster);
	Falster.read_temperatures();
	
	
	Falster.tempPerDayExtended();
	
	TH1D* FalsterHist = new TH1D("hPhi", "Falsterbo; day; Temperature (#circ C)", 
			Falster.avgOfData.size()-1 , 0, Falster.avgOfData.size());
	
	for (unsigned int i = 0; i < Falster.avgOfData.size(); i++){
		FalsterHist->SetBinContent(i,Falster.avgOfData.at(i));
	}
		
	leg->AddEntry(FalsterHist, "", "L");
	FalsterHist->SetLineColor(kGray+2);
	FalsterHist->Draw("SAME");
	
	
	
	
	string pathUmea = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Umea.csv";
	tempTrender Umea(pathUmea);
	Umea.read_temperatures();
	
	
	Umea.tempPerDayExtended();
	
	TH1D* UmeaHist = new TH1D("hPhi", "Umea; day; Temperature (#circ C)", 
			Umea.avgOfData.size()-1 , 0, Umea.avgOfData.size());
	
	for (unsigned int i = 0; i < Umea.avgOfData.size(); i++){
		UmeaHist->SetBinContent(i,Umea.avgOfData.at(i));
	}
	leg->AddEntry(UmeaHist, "", "L");
	UmeaHist->SetLineColor(kBlue-6);
	UmeaHist->Draw("SAME");
	
	
	
	
	string pathKarl = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-openda_Karlstad.csv";
	tempTrender Karl(pathKarl);
	Karl.read_temperatures();
	
	
	Karl.tempPerDayExtended();
	
	TH1D* KarlHist = new TH1D("hPhi", "Karlstad; day; Temperature (#circ C)", 
			Karl.avgOfData.size()-1 , 0, Karl.avgOfData.size());
	
	for (unsigned int i = 0; i < Karl.avgOfData.size(); i++){
		KarlHist->SetBinContent(i,Karl.avgOfData.at(i));
	}
	leg->AddEntry(KarlHist, "", "L");
	KarlHist->SetLineColor(kOrange +7);
	KarlHist->Draw("SAME");
	
	
	
	
	string pathVisby ="/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Visby.csv";
	tempTrender Visby(pathVisby);
	Visby.read_temperatures();
	
	
	Visby.tempPerDayExtended();
	
	TH1D* VisbyHist = new TH1D("hPhi", "Visby; day; Temperature (#circ C)", 
			Visby.avgOfData.size()-1 , 0, Visby.avgOfData.size());
	
	for (unsigned int i = 0; i < Visby.avgOfData.size(); i++){
		VisbyHist->SetBinContent(i,Visby.avgOfData.at(i));
	}
	leg->AddEntry(VisbyHist, "", "L");
	VisbyHist->SetLineColor(kBlack);
	VisbyHist->Draw("SAME");
	
	
	
	
	leg->Draw();
	
}
