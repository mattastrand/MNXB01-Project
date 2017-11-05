#include <iostream>
#include "tempTrender.h"

tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
	its_filePath = filePath; 

}

tempTrender::~tempTrender(){
}


void plotYears(){
	
	
	TCanvas* c1 = new TCanvas("c1", "hPhi canvas", 1400, 900);
	TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);



	string pathSoder = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	tempTrender Soder(pathSoder);
	
	Soder.read_temperatures();
	Soder.tempEveryYear();
	cout << Soder.warmAndCold[1] << endl;
	Soder.tempPerDay(Soder.warmAndCold[1]);
	TH1D* SoderWarmHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
			Soder.datavector.size() -1, 0, Soder.datavector.size());
	
	for(unsigned int i = 0 ; i< Soder.datavector.size() ; i++){
		SoderWarmHist->SetBinContent(i,Soder.datavector.at(i));
	}
	
	Soder.tempPerDay(Soder.warmAndCold[3]);
	TH1D* SoderColdHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
			Soder.datavector.size() -1, 0, Soder.datavector.size());
	
	for(unsigned int i = 0 ; i< Soder.datavector.size() ; i++){
		SoderColdHist->SetBinContent(i,Soder.datavector.at(i));
	}
	
	
	SoderWarmHist->SetLineColor(kRed);
	SoderWarmHist->SetMinimum(-15);
	SoderWarmHist->SetMaximum(24);
	SoderWarmHist->Draw();
	SoderColdHist->SetLineColor(kRed);
	SoderColdHist->Draw("SAME");
	
	//string pathUpp = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	//tempTrender Upp(pathUpp);
	
	//Upp.read_temperatures();
	//Upp.tempEveryYear();
	
	
	//string pathLund = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	//tempTrender Lund(pathLund);

	//Lund.read_temperatures();
	//Lund.tempEveryYear();
	
	
	//string pathLule = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	//tempTrender Lule(pathLule);
	
	//Lule.read_temperatures();
	//Lule.tempEveryYear();

	
	//string pathBoras = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Boras.csv";
	//tempTrender Boras(pathBoras);
	
	//Boras.read_temperatures();
	//Boras.tempEveryYear();
	
	
	//string pathFalun = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falun.csv";
	//tempTrender Falun(pathFalun);
	
	//Falun.read_temperatures();
	//Falun.tempEveryYear();
	
	
	//string pathFalster = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falsterbo.csv";
	//tempTrender Falster(pathFalster);
	
	//Falster.read_temperatures();
	//Falster.tempEveryYear();
	
	
	string pathUmea = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Umea.csv";
	tempTrender Umea(pathUmea);
	
	Umea.read_temperatures();
	Umea.tempEveryYear();
	
	cout << Umea.warmAndCold[1] << endl;
	Umea.tempPerDay(Umea.warmAndCold[1]);
	TH1D* UmeaWarmHist = new TH1D("hPhi", "Umea; Day; Temperature", 
			Umea.datavector.size() -1, 0, Umea.datavector.size());
	
	for(unsigned int i = 0 ; i< Umea.datavector.size() ; i++){
		UmeaWarmHist->SetBinContent(i,Umea.datavector.at(i));
	}
	
	Umea.tempPerDay(Umea.warmAndCold[3]);
	TH1D* UmeaColdHist = new TH1D("hPhi", "Umea; Day; Temperature", 
			Umea.datavector.size() -1, 0, Umea.datavector.size());
	
	for(unsigned int i = 0 ; i< Umea.datavector.size() ; i++){
		UmeaColdHist->SetBinContent(i,Umea.datavector.at(i));
	}
	
	UmeaWarmHist->SetLineColor(kBlue);
	UmeaWarmHist->SetMinimum(-15);
	UmeaWarmHist->SetMaximum(24);
	UmeaWarmHist->Draw("SAME");
	UmeaColdHist->SetLineColor(kBlue);
	UmeaColdHist->Draw("SAME");
	
	
	//string pathKarl = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-openda_Karlstad.csv";
	//tempTrender Karl(pathKarl);
	
	//Karl.read_temperatures();
	//Karl.tempEveryYear();
	
	
	//string pathVisby ="/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Visby.csv";
	//tempTrender Visby(pathVisby);
	
	//Visby.read_temperatures();
	//Visby.tempEveryYear();
	
}
