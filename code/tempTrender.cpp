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


void testFunc(){
	
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
	
	
	Soder.tempPerDay(1973);
	
	TH1D* SoderHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
			Soder.datavector.size() -1, 0, Soder.datavector.size());
	
	for(unsigned int i = 0 ; i< Soder.datavector.size() ; i++){
		SoderHist->SetBinContent(i,Soder.datavector.at(i));
	}

	
	//Soder.tempEveryYear();
	
	//TH1D* SoderHist = new TH1D("Soder", "Soderarm; Year; Temperature",
			//Soder.yearNumber.size()-1, Soder.yearNumber.front(), Soder.yearNumber.back()-1);
	
	//for (unsigned int i = 0; i< Soder.yearNumber.size(); i++){
		//SoderHist->SetBinContent(i,Soder.yearTemp.at(i));
	//}
	
	//cout << SoderHist->GetBinContent(SoderHist->GetMinimumBin()) << endl;
	//cout << Soder.yearNumber.at(SoderHist->GetMinimumBin()) << endl;
	//cout << SoderHist->GetBinContent(SoderHist->GetMaximumBin()) << endl;
	//cout << Soder.yearNumber.at(SoderHist->GetMaximumBin()) << endl;
	//for (unsigned int i =0; i< Soder.warmAndCold.size();i++){
		//cout << Soder.warmAndCold.at(i) << endl;
	//}
	
	//SoderHist->Fit(func,"QOR");
	
	leg->AddEntry(SoderHist, "","L");
	
	SoderHist->SetLineColor(kRed);
	SoderHist->SetMinimum(-15);
	SoderHist->SetMaximum(24);
	SoderHist->Draw();
	

	//string pathUpp = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	//tempTrender Upp(pathUpp);

	
	//Upp.read_temperatures();

	
	//Upp.tempEveryYear();
	
	//TH1D* UppHist = new TH1D("Upp", "Uppsala; Year; Temperature",
			//Upp.yearNumber.size()-1, Upp.yearNumber.front(), Upp.yearNumber.back()-1);
	
	//for (unsigned int i = 0; i< Upp.yearNumber.size(); i++){
		//UppHist->SetBinContent(i,Upp.yearTemp.at(i));
	//}
	
	//cout << UppHist->GetBinContent(UppHist->GetMinimumBin()) << endl;
	////cout << Upp.yearNumber.at(UppHist->GetMinimumBin()) << endl;
	//cout << UppHist->GetBinContent(UppHist->GetMaximumBin()) << endl;
	////cout << Upp.yearNumber.at(UppHist->GetMaximumBin()) << endl;
	
	//UppHist->SetLineColor(kMagenta);
	//UppHist->SetMinimum(-20);
	//UppHist->SetMaximum(30),
	//UppHist->Draw("SAME");

	
	//TH1D* UrbanUppHist = new TH1D("Upp", "Uppsala Urban; Year; Temperature",
			//Upp.yearNumber.size()-1, Upp.yearNumber.front(), Upp.yearNumber.back()-1);
	
	//for (unsigned int i = 0; i< Upp.yearNumber.size(); i++){
		//UrbanUppHist->SetBinContent(i,Upp.urbanYearTemp.at(i));
	//}
	
	
	//leg->AddEntry(UppHist, "", "L");
	//leg->AddEntry(UrbanUppHist, "", "L");
	//UrbanUppHist->SetLineColor(kMagenta +3);
	//UrbanUppHist->Draw("SAME");
	
	
	//string pathLund = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	//tempTrender Lund(pathLund);

	//Lund.read_temperatures();

	//Lund.tempPerDay(1973);
	
	
	//TH1D* LundHist = new TH1D("hPhi", "Lund; Day; Temperature", 
			//Lund.datavector.size(), 0, Lund.datavector.size());
	
	//for(unsigned int i = 0 ; i< Lund.datavector.size() ; i++){
		//LundHist->SetBinContent(i,Lund.datavector.at(i));
	//}
	

	//leg->AddEntry(LundHist, "", "L");
	//LundHist->SetLineColor(kBlue);
	//LundHist->Draw("SAME");
	
	
	//string pathLule = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	//tempTrender Lule(pathLule);
	//Lule.read_temperatures();
	
	//Lule.tempPerDay(1973);
	
	//TH1D* LuleHist = new TH1D("hPhi", "Lulea; Day; Temperature", 
			//Lule.datavector.size(), 0, Lule.datavector.size());
	
	//for(unsigned int i = 0 ; i< Lule.datavector.size() ; i++){
		//LuleHist->SetBinContent(i,Lule.datavector.at(i));
	//}
	
	
	//leg->AddEntry(LuleHist, "", "L");
	//LuleHist->SetLineColor(kCyan);
	//LuleHist->Draw("SAME");
	
	
	//string pathBoras = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Boras.csv";
	//tempTrender Boras(pathBoras);
	//Boras.read_temperatures();
	

	//string pathFalun = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falun.csv";
	//tempTrender Falun(pathFalun);
	//Falun.read_temperatures();
	
	
	//string pathFalster = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falsterbo.csv";
	//tempTrender Falster(pathFalster);
	//Falster.read_temperatures();

	
	//string pathUmea = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Umea.csv";
	//tempTrender Umea(pathUmea);
	//Umea.read_temperatures();
	
	
	//string pathKarl = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-openda_Karlstad.csv";
	//tempTrender Karl(pathKarl);
	//Karl.read_temperatures();
	
	
	//string pathVisby ="/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Visby.csv";
	//tempTrender Visby(pathVisby);
	//Visby.read_temperatures();
	
	leg->Draw();
	
}

int main(){

	
	

	string pathToFile = "/home/magnus/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender Upp(pathToFile);
	Upp.read_temperatures();
	Upp.tempPerDayExtended();
	
	
	TH1D* UppHist = new TH1D("Upp", "Uppsala; Year; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppHist->SetBinContent(i,Upp.avgOfData.at(i));
	}
	
	
	TH1D* UppWarmHist = new TH1D("Upp", "Uppsala; Year; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppWarmHist->SetBinContent(i,Upp.theWarmestDays.at(i));
	}
	
	TH1D* UppColdHist = new TH1D("Upp", "Uppsala; Year; Temperature (#circ C)",
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

}
