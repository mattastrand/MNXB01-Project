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
	//The histograms are pretty neatly set up at the moment.
	//To use them, just uncomment relevant lines, and make sure that they are all drawn 
	// to the same canvas.
	
	
	//string pathSoder = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	//tempTrender Soder(pathSoder);
	//Soder.read_temperatures();
	//Soder.tempPerDay(1973);
	
	//TH1D* SoderHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
			//Soder.datavector.size(), 0, Soder.datavector.size());
	
	//for(unsigned int i = 0 ; i< Soder.datavector.size() ; i++){
		//SoderHist->SetBinContent(i,Soder.datavector.at(i));
	//}
	
	
	//Soder.tempPerDayExtended();

	//TH1D* SoderHist = new TH1D("hPhi", "Soderarm; Day; Temperature", 
			//Soder.avgOfData.size(), 0, Soder.avgOfData.size());
	
	//for(unsigned int i = 0 ; i< Soder.avgOfData.size() ; i++){
		//SoderHist->SetBinContent(i,Soder.avgOfData.at(i));
	//}
	
	
	//Soder.tempEveryYear();
	
	//TH1D* SoderHist = new TH1D("Soder", "Soderarm; Year; Temperature",
			//Soder.yearNumber.size()-1, Soder.yearNumber.front(), Soder.yearNumber.back()-1);
	
	//for (unsigned int i = 0; i< Soder.yearNumber.size(); i++){
		//SoderHist->SetBinContent(i,Soder.yearTemp.at(i));
	//}
	
	//leg->AddEntry(SoderHist, "", "F");
	//SoderHist->SetLineColor(11);
	//SoderHist->SetMinimum(-20);
	//SoderHist->SetMaximum(30);
	//SoderHist->Draw();
	
	
	
	//string pathUpp = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	//tempTrender Upp(pathUpp);
	
	//Upp.read_temperatures();
	
	//Upp.tempPerDayExtended();
	
	//TH1D* UppHist = new TH1D ("hPhi", "Uppsala; Day; Temperature", 
			//Upp.avgOfData.size(), 0, Upp.avgOfData.size());
			
	//for(unsigned int i = 0 ; i< Upp.avgOfData.size() ; i++){
		//UppHist->SetBinContent(i,Upp.avgOfData.at(i));
	//}
	
	
	//Upp.tempEveryYear();
	
	//TH1D* UppHist = new TH1D("Upp", "Uppsala; Year; Temperature",
			//Upp.yearNumber.size()-1, Upp.yearNumber.front(), Upp.yearNumber.back()-1);
	
	//for (unsigned int i = 0; i< Upp.yearNumber.size(); i++){
		//UppHist->SetBinContent(i,Upp.yearTemp.at(i));
	//}
	
	
	//UppHist->SetLineColor(35);
	//UppHist->SetMinimum(-20);
	//UppHist->SetMaximum(30),
	//UppHist->Draw();
	
	//TH1D* UrbanUppHist = new TH1D ("hPhi", "Uppsala Urban; Day; Temperature", 
			//Upp.urbanAvgOfData.size(), 0, Upp.urbanAvgOfData.size());
			
	//for(unsigned int i = 0 ; i< Upp.urbanAvgOfData.size() ; i++){
		//UrbanUppHist->SetBinContent(i,Upp.urbanAvgOfData.at(i));
	//}
	
	
	//TH1D* UrbanUppHist = new TH1D("Upp", "Uppsala Urban; Year; Temperature",
			//Upp.yearNumber.size()-1, Upp.yearNumber.front(), Upp.yearNumber.back()-1);
	
	//for (unsigned int i = 0; i< Upp.yearNumber.size(); i++){
		//UrbanUppHist->SetBinContent(i,Upp.urbanYearTemp.at(i));
	//}
	
	
	//leg->AddEntry(UppHist, "", "F");
	//leg->AddEntry(UrbanUppHist, "", "F");
	//UrbanUppHist->Draw("SAME");
	//leg->Draw();
	
	
	//SoderHist->Draw("Same");
	
	
	//string pathLund = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	//tempTrender Lund(pathLund);

	//Lund.read_temperatures();

	//Lund.tempPerDay(1973);
	
	
	//TH1D* LundHist = new TH1D("hPhi", "Lund; Day; Temperature", 
			//Lund.datavector.size(), 0, Lund.datavector.size());
	
	//for(unsigned int i = 0 ; i< Lund.datavector.size() ; i++){
		//LundHist->SetBinContent(i,Lund.datavector.at(i));
	//}
	
	
	
	
	//Lund.tempPerDayExtended();
	
	//TH1D* LundHist = new TH1D("hPhi", "Lund; phi; Counts", 
			//Lund.avgOfData.size(), 0, Lund.avgOfData.size());
	
	//for (unsigned int i = 0; i < Lund.avgOfData.size(); i++){
		//LundHist->SetBinContent(i,Lund.avgOfData.at(i));
	//}
	
	//leg->AddEntry(LundHist, "", "F");
	//LundHist->SetLineColor(24);
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
	
	
	
	
	
	
	//Lule.tempPerDayExtended();
	
	//TH1D* LuleHist = new TH1D("hPhi", "Lulea; phi; Counts", 
			//Lule.avgOfData.size(), 0, Lule.avgOfData.size());
	
	//for (unsigned int i = 0; i < Lule.avgOfData.size(); i++){
		//LuleHist->SetBinContent(i,Lule.avgOfData.at(i));
	//}
		
	//leg->AddEntry(LuleHist, "", "F");
	//LuleHist->SetLineColor(12);
	//LuleHist->Draw("SAME");
	
	
	
	//leg->Draw();
	
}

int main(){
//	string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
//	tempTrender Upp(pathToFile);
//	Upp.read_temperatures();
//	Upp.tempPerDayExtended();
//	Upp.tempEveryYear();
//	cout << Upp.warmAndCold.size() << endl;
//	for (unsigned int i = 0; i < Upp.warmAndCold.size(); i ++){
//		cout << Upp.warmAndCold[i] << endl;
//	}
//	Upp.tempPerDay(1973);
//	for (unsigned int i = 0; i< Upp.datavector.size();i++){
//		cout << Upp.datavector.at(i) << endl;
//		cout << Upp.urbanDatavector.at(i) << endl;
//	}

//	string pathLule = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
//	tempTrender Lule(pathLule);
//	Lule.read_temperatures();
//	Lule.tempPerDay(1973);
//	for (unsigned int i = 0 ; i< Lule.datavector.size(); i++){
//		cout << Lule.datavector.at(i) << endl;
//	}
//	Lule.tempEveryYear();
//	for (unsigned int i = 0; i < Lule.yearTemp.size(); i ++){
//		cout << "temp " << Lule.yearTemp[i] << " at year " << Lule.yearNumber[i] << endl;
//	}
//	cout << Lule.warmAndCold.size() << endl;
//	for (unsigned int i = 0; i < Lule.warmAndCold.size(); i ++){
//		cout << Lule.warmAndCold[i] << endl;
//	}
	
//	string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv"; //Put the path to your data file here

//	tempTrender t(pathToFile);
//	t.read_temperatures();
	
//	t.tempPerDay(1973);
//	t.tempPerDayExtended();

}
