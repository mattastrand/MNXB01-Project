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
	
	
	TCanvas* c1 = new TCanvas("c1", "Comparing warm and cold years - canvas", 1600, 1200);
	TLegend *leg1 = new TLegend(0.50,0.5,0.75, 0.3);
	TLegend *leg2 = new TLegend(0.50,0.5,0.75, 0.3);
	c1->Divide(2,1);


//	string pathSoder = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
//	tempTrender Soder(pathSoder);
	
//	Soder.read_temperatures();
//	Soder.tempEveryYear();
//	Soder.tempPerDay(Soder.warmAndCold[1]);
//	TH1D* SoderWarmHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
//			Soder.datavector.size() -1, 0, Soder.datavector.size());
	
//	for(unsigned int i = 0 ; i< Soder.datavector.size() ; i++){
//		SoderWarmHist->SetBinContent(i,Soder.datavector.at(i));
//	}
	
//	Soder.tempPerDay(Soder.warmAndCold[3]);
//	TH1D* SoderColdHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
//			Soder.datavector.size() -1, 0, Soder.datavector.size());
	
//	for(unsigned int i = 0 ; i< Soder.datavector.size() ; i++){
//		SoderColdHist->SetBinContent(i,Soder.datavector.at(i));
//	}
	
	
//	SoderWarmHist->SetLineColor(kRed);
//	SoderWarmHist->SetMinimum(-15);
//	SoderWarmHist->SetMaximum(24);
//	SoderWarmHist->Draw();
//	SoderColdHist->SetLineColor(kRed);
//	SoderColdHist->Draw("SAME");
	
	
	
//	string pathUpp = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
//	tempTrender Upp(pathUpp);
	
//	Upp.read_temperatures();
//	Upp.tempEveryYear();
	
//	Upp.tempPerDay(Upp.warmAndCold[1]);
//	TH1D* UppWarmHist = new TH1D("hPhi", "Uppsala; Day; Temperature", 
//			Upp.datavector.size() -1, 0, Upp.datavector.size());
	
//	for(unsigned int i = 0 ; i< Upp.datavector.size() ; i++){
//		UppWarmHist->SetBinContent(i,Upp.datavector.at(i));
//	}
	
//	Upp.tempPerDay(Upp.warmAndCold[3]);
//	TH1D* UppColdHist = new TH1D("hPhi", "Uppsala; Day; Temperature", 
//			Upp.datavector.size() -1, 0, Upp.datavector.size());
	
//	for(unsigned int i = 0 ; i< Upp.datavector.size() ; i++){
//		UppColdHist->SetBinContent(i,Upp.datavector.at(i));
//	}
	
	
//	UppWarmHist->SetLineColor(kRed);
//	UppWarmHist->SetMinimum(-15);
//	UppWarmHist->SetMaximum(24);
//	UppWarmHist->Draw("SAME");
//	UppColdHist->SetLineColor(kRed);
//	UppColdHist->Draw("SAME");
	
	
	
	string pathLund = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	tempTrender Lund(pathLund);

	Lund.read_temperatures();
	Lund.tempEveryYear();
	
//	Lund.tempPerDay(Lund.warmAndCold[1]);
//	TH1D* LundWarmHist = new TH1D("hPhi", "Lund; Day; Temperature", 
//			Lund.datavector.size() -1, 0, Lund.datavector.size());
	
//	for(unsigned int i = 0 ; i< Lund.datavector.size() ; i++){
//		LundWarmHist->SetBinContent(i,Lund.datavector.at(i));
//	}
	
	Lund.tempPerDay(Lund.warmAndCold[3]);
	TH1D* LundColdHist = new TH1D("hPhi", "Lund; Day; Temperature (#circ C)", 
			Lund.datavector.size() -1, 0, Lund.datavector.size());
	
	for(unsigned int i = 0 ; i< Lund.datavector.size() ; i++){
		LundColdHist->SetBinContent(i,Lund.datavector.at(i));
	}
	
	
//	LundWarmHist->SetLineColor(kRed);
//	LundWarmHist->SetMinimum(-15);
//	LundWarmHist->SetMaximum(24);
//	LundWarmHist->Draw("SAME");
	LundColdHist->SetMinimum(-35);
	LundColdHist->SetMaximum(30);
	LundColdHist->SetLineColor(kCyan +2);
	c1->cd(1);
	LundColdHist->Draw();
	
	
	
	string pathLule = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	tempTrender Lule(pathLule);
	
	Lule.read_temperatures();
	Lule.tempEveryYear();

//	Lule.tempPerDay(Lule.warmAndCold[1]);
//	TH1D* LuleWarmHist = new TH1D("hPhi", "Lulea; Day; Temperature", 
//			Lule.datavector.size() -1, 0, Lule.datavector.size());
	
//	for(unsigned int i = 0 ; i< Lule.datavector.size() ; i++){
//		LuleWarmHist->SetBinContent(i,Lule.datavector.at(i));
//	}
	
	Lule.tempPerDay(Lule.warmAndCold[3]);
	TH1D* LuleColdHist = new TH1D("hPhi", "Lulea; Day; Temperature (#circ C)", 
			Lule.datavector.size() -1, 0, Lule.datavector.size());
	
	for(unsigned int i = 0 ; i< Lule.datavector.size() ; i++){
		LuleColdHist->SetBinContent(i,Lule.datavector.at(i));
	}
	
	
//	LuleWarmHist->SetLineColor(kRed);
//	LuleWarmHist->SetMinimum(-15);
//	LuleWarmHist->SetMaximum(24);
//	LuleWarmHist->Draw("SAME");
	LuleColdHist->SetLineColor(kBlue);
	c1->cd(1);
	LuleColdHist->Draw("SAME");
	
	

	leg1->AddEntry(LundColdHist, "Warmest cold-year (Lund 1980)", "L");
	leg1->AddEntry(LuleColdHist, "Coldest cold-year (Lulea 1985)", "L");
	leg1->Draw();
	
	
	
//	string pathBoras = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Boras.csv";
//	tempTrender Boras(pathBoras);
	
//	Boras.read_temperatures();
//	Boras.tempEveryYear();
	
//	Boras.tempPerDay(Boras.warmAndCold[1]);
//	TH1D* BorasWarmHist = new TH1D("hPhi", "Boras; Day; Temperature", 
//			Boras.datavector.size() -1, 0, Boras.datavector.size());
	
//	for(unsigned int i = 0 ; i< Boras.datavector.size() ; i++){
//		BorasWarmHist->SetBinContent(i,Boras.datavector.at(i));
//	}
	
//	Boras.tempPerDay(Boras.warmAndCold[3]);
//	TH1D* BorasColdHist = new TH1D("hPhi", "Boras; Day; Temperature", 
//			Boras.datavector.size() -1, 0, Boras.datavector.size());
	
//	for(unsigned int i = 0 ; i< Boras.datavector.size() ; i++){
//		BorasColdHist->SetBinContent(i,Boras.datavector.at(i));
//	}
	
	
//	BorasWarmHist->SetLineColor(kRed);
//	BorasWarmHist->SetMinimum(-15);
//	BorasWarmHist->SetMaximum(24);
//	BorasWarmHist->Draw("SAME");
//	BorasColdHist->SetLineColor(kRed);
//	BorasColdHist->Draw("SAME");
	
	
	
//	string pathFalun = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falun.csv";
//	tempTrender Falun(pathFalun);
	
//	Falun.read_temperatures();
//	Falun.tempEveryYear();
	
//	Falun.tempPerDay(Falun.warmAndCold[1]);
//	TH1D* FalunWarmHist = new TH1D("hPhi", "Falun; Day; Temperature", 
//			Falun.datavector.size() -1, 0, Falun.datavector.size());
	
//	for(unsigned int i = 0 ; i< Falun.datavector.size() ; i++){
//		FalunWarmHist->SetBinContent(i,Falun.datavector.at(i));
//	}
	
//	Falun.tempPerDay(Upp.warmAndCold[3]);
//	TH1D* FalunColdHist = new TH1D("hPhi", "Falun; Day; Temperature", 
//			Falun.datavector.size() -1, 0, Falun.datavector.size());
	
//	for(unsigned int i = 0 ; i< Falun.datavector.size() ; i++){
//		FalunColdHist->SetBinContent(i,Falun.datavector.at(i));
//	}
	
	
//	FalunWarmHist->SetLineColor(kRed);
//	FalunWarmHist->SetMinimum(-15);
//	FalunWarmHist->SetMaximum(24);
//	FalunWarmHist->Draw("SAME");
//	FalunColdHist->SetLineColor(kRed);
//	FalunColdHist->Draw("SAME");
	
	
	
	string pathFalster = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Falsterbo.csv";
	tempTrender Falster(pathFalster);
	
	Falster.read_temperatures();
	Falster.tempEveryYear();
	
	Falster.tempPerDay(Falster.warmAndCold[1]);
	TH1D* FalsterWarmHist = new TH1D("hPhi", "Falsterbo; Day; Temperature (#circ C)", 
			Falster.datavector.size() -1, 0, Falster.datavector.size());
	
	for(unsigned int i = 0 ; i< Falster.datavector.size() ; i++){
		FalsterWarmHist->SetBinContent(i,Falster.datavector.at(i));
	}
	
//	Falster.tempPerDay(Falster.warmAndCold[3]);
//	TH1D* FalsterColdHist = new TH1D("hPhi", "Falsterbo; Day; Temperature", 
//			Falster.datavector.size() -1, 0, Falster.datavector.size());
	
//	for(unsigned int i = 0 ; i< Falster.datavector.size() ; i++){
//		FalsterColdHist->SetBinContent(i,Falster.datavector.at(i));
//	}
	
	
	FalsterWarmHist->SetLineColor(kRed);
	FalsterWarmHist->SetMinimum(-20);
	FalsterWarmHist->SetMaximum(30);
	c1->cd(2);
	FalsterWarmHist->Draw();
//	FalsterColdHist->SetLineColor(kRed);
//	FalsterColdHist->Draw("SAME");
	
	
	
	string pathUmea = "/home/magnus/MNXB01/2017HT/Project/datasets/smhi-opendata_Umea.csv";
	tempTrender Umea(pathUmea);
	
	Umea.read_temperatures();
	Umea.tempEveryYear();
	
	cout << Umea.warmAndCold[1] << endl;
	Umea.tempPerDay(Umea.warmAndCold[1]);
	TH1D* UmeaWarmHist = new TH1D("hPhi", "Umea; Day; Temperature (#circ C)", 
			Umea.datavector.size() -1, 0, Umea.datavector.size());
	
	for(unsigned int i = 0 ; i< Umea.datavector.size() ; i++){
		UmeaWarmHist->SetBinContent(i,Umea.datavector.at(i));
	}
	
//	Umea.tempPerDay(Umea.warmAndCold[3]);
//	TH1D* UmeaColdHist = new TH1D("hPhi", "Umea; Day; Temperature", 
//			Umea.datavector.size() -1, 0, Umea.datavector.size());
	
//	for(unsigned int i = 0 ; i< Umea.datavector.size() ; i++){
//		UmeaColdHist->SetBinContent(i,Umea.datavector.at(i));
//	}
	
	UmeaWarmHist->SetLineColor(kOrange);
//	UmeaWarmHist->SetMinimum(-15);
//	UmeaWarmHist->SetMaximum(24);
	c1->cd(2);
	UmeaWarmHist->Draw("SAME");
//	UmeaColdHist->SetLineColor(kRed);
//	UmeaColdHist->Draw("SAME");
	
	
	
//	string pathKarl = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-openda_Karlstad.csv";
//	tempTrender Karl(pathKarl);
	
//	Karl.read_temperatures();
//	Karl.tempEveryYear();
	
//	Karl.tempPerDay(Karl.warmAndCold[1]);
//	TH1D* KarlWarmHist = new TH1D("hPhi", "Karlstad; Day; Temperature", 
//			Karl.datavector.size() -1, 0, Karl.datavector.size());
	
//	for(unsigned int i = 0 ; i< Karl.datavector.size() ; i++){
//		KarlWarmHist->SetBinContent(i,Karl.datavector.at(i));
//	}
	
//	Karl.tempPerDay(Karl.warmAndCold[3]);
//	TH1D* KarlColdHist = new TH1D("hPhi", "Karlstad; Day; Temperature", 
//			Karl.datavector.size() -1, 0, Karl.datavector.size());
	
//	for(unsigned int i = 0 ; i< Karl.datavector.size() ; i++){
//		KarlColdHist->SetBinContent(i,Karl.datavector.at(i));
//	}
	
	
//	KarlWarmHist->SetLineColor(kRed);
//	KarlWarmHist->SetMinimum(-15);
//	KarlWarmHist->SetMaximum(24);
//	KarlWarmHist->Draw("SAME");
//	KarlColdHist->SetLineColor(kRed);
//	KarlColdHist->Draw("SAME");
	

	
//	string pathVisby ="/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Visby.csv";
//	tempTrender Visby(pathVisby);
	
//	Visby.read_temperatures();
//	Visby.tempEveryYear();
	
//	Visby.tempPerDay(Visby.warmAndCold[1]);
//	TH1D* VisbyWarmHist = new TH1D("hPhi", "Visby; Day; Temperature", 
//			Visby.datavector.size() -1, 0, Visby.datavector.size());
	
//	for(unsigned int i = 0 ; i< Visby.datavector.size() ; i++){
//		VisbyWarmHist->SetBinContent(i,Visby.datavector.at(i));
//	}
	
//	Visby.tempPerDay(Visby.warmAndCold[3]);
//	TH1D* VisbyColdHist = new TH1D("hPhi", "Visby; Day; Temperature", 
//			Visby.datavector.size() -1, 0, Visby.datavector.size());
	
//	for(unsigned int i = 0 ; i< Visby.datavector.size() ; i++){
//		VisbyColdHist->SetBinContent(i,Visby.datavector.at(i));
//	}
	
	
//	VisbyWarmHist->SetLineColor(kRed);
//	VisbyWarmHist->SetMinimum(-15);
//	VisbyWarmHist->SetMaximum(24);
//	VisbyWarmHist->Draw("SAME");
//	VisbyColdHist->SetLineColor(kRed);
//	VisbyColdHist->Draw("SAME");

leg2->AddEntry(UmeaWarmHist, "Coldest warm-year (Umea 2014)", "L");
leg2->AddEntry(FalsterWarmHist, "Warmest warm-year (Falsterbo 2014)", "L");
leg2->Draw();
	
}
