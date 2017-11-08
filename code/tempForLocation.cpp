#include "tempTrender.h"

tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
	its_filePath = filePath; 

}

tempTrender::~tempTrender(){
}

void plotTempLocation(){
	
	
	//TCanvas* c1 = new TCanvas("c1", "Location canvas", 1400, 900);
	TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);
	
	string pathSoder = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	tempTrender Soder(pathSoder);
	
	Soder.read_temperatures();
	Soder.tempEveryYear();
	
	string pathUpp = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender Upp(pathUpp);
	
	Upp.read_temperatures();
	Upp.tempEveryYear();
	
	
	string pathLund = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	tempTrender Lund(pathLund);

	Lund.read_temperatures();
	Lund.tempEveryYear();
	
	
	string pathLule = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	tempTrender Lule(pathLule);
	
	Lule.read_temperatures();
	Lule.tempEveryYear();

	
	string pathBoras = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Boras.csv";
	tempTrender Boras(pathBoras);
	
	Boras.read_temperatures();
	Boras.tempEveryYear();
	
	
	string pathFalun = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falun.csv";
	tempTrender Falun(pathFalun);
	
	Falun.read_temperatures();
	Falun.tempEveryYear();
	
	
	string pathFalster = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falsterbo.csv";
	tempTrender Falster(pathFalster);
	
	Falster.read_temperatures();
	Falster.tempEveryYear();
	
	
	string pathUmea = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Umea.csv";
	tempTrender Umea(pathUmea);
	
	Umea.read_temperatures();
	Umea.tempEveryYear();
	
	
	string pathKarl = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-openda_Karlstad.csv";
	tempTrender Karl(pathKarl);
	
	Karl.read_temperatures();
	Karl.tempEveryYear();
	
	
	string pathVisby ="/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Visby.csv";
	tempTrender Visby(pathVisby);

	Visby.read_temperatures();
	Visby.tempEveryYear();
	
	
//	Code to obtain the warmest and coldest years for each location:
//	cout << "Soder: " << Soder.warmAndCold[1] << " " << Soder.warmAndCold[3] << endl;
//	cout << "Upp: " << Upp.warmAndCold[1] << " " << Upp.warmAndCold[3] << endl;
//	cout << "Lund: " << Lund.warmAndCold[1] << " " << Lund.warmAndCold[3] << endl;
//	cout << "Lule: " << Lule.warmAndCold[1] << " " << Lule.warmAndCold[3] << endl;
//	cout << "Boras: " << Boras.warmAndCold[1] << " " << Boras.warmAndCold[3] << endl;
//	cout << "Falun: " << Falun.warmAndCold[1] << " " << Falun.warmAndCold[3] << endl;
//	cout << "Falster: " << Falster.warmAndCold[1] << " " << Falster.warmAndCold[3] << endl;
//	cout << "Umea: " << Umea.warmAndCold[1] << " " << Umea.warmAndCold[3] << endl;
//	cout << "Karl: " << Karl.warmAndCold[1] << " " << Karl.warmAndCold[3] << endl;
//	cout << "Visby: " << Visby.warmAndCold[1] << " " << Visby.warmAndCold[3] << endl;

	
	
	TCanvas *cb = new TCanvas("cb","cb",1200,900);
	//THStack *hs = new THStack("hs","Stacked 1D histograms");
	cb->SetGrid();
	gStyle->SetHistMinimumZero();
	TH1F *h1b = new TH1F("h1b","Option B example; ; Temperature (#circ C)",10,0,10);
	h1b->SetFillColor(kRed);
	h1b->SetBarWidth(0.2);
	h1b->SetBarOffset(0.1);
	h1b->SetStats(0);
	h1b->SetMinimum(-5);
	h1b->SetMaximum(15);
	h1b->SetBinContent(1,Soder.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(1,"Soderarm 2008 (red), 1985 (blue)"); // 2008 (red), 1985 (blue) including Y lines.
	//h1b->Fill(1,Soder.warmAndCold[1]);
	h1b->SetBinContent(2,Upp.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(2,"Uppsala 1723, 1867"); // 1723, 1867 including Y lines.
	h1b->SetBinContent(3,Lund.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(3,"Lund 1975, 1980"); // 1975, 1980 including Y lines.
	h1b->SetBinContent(4,Lule.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(4,"Lulea 1960, 1985"); // 1953, 1985 including Y lines.
	h1b->SetBinContent(5,Boras.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(5,"Boras 1990, 2010"); // 1990, 2010 including Y lines.
	h1b->SetBinContent(6,Falun.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(6,"Falun 1955, 1985"); // 1955, 1985 including Y lines.
	h1b->SetBinContent(7,Falster.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(7,"Falsterbo 2014, 1979"); // 2014, 1979 including Y lines.
	h1b->SetBinContent(8,Umea.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(8,"Umea 2014, 1985"); // 2014, 1985 including Y lines.
	h1b->SetBinContent(9,Karl.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(9,"Karlstad 1955, 1987"); // 1955, 1985 including Y lines.
	h1b->SetBinContent(10,Visby.warmAndCold[0]);
	h1b->GetXaxis()->SetBinLabel(10,"Visby 1953, 1985"); // 1953, 1985 including Y lines.

	//hs->Add(h1b);
	h1b->Draw("b");
	
	TH1F *h3b = new TH1F("h3b", "h3b",10,0,10);
	h3b->SetFillColor(kGreen +1);
	h3b->SetBarWidth(0.2);
	h3b->SetBarOffset(0.4);
	h3b->SetStats(0);
    h3b->SetBinContent(1,Soder.meanTempEveryYear);	
	h3b->SetBinContent(2,Upp.meanTempEveryYear);
	h3b->SetBinContent(3,Lund.meanTempEveryYear);
	h3b->SetBinContent(4,Lule.meanTempEveryYear);
	h3b->SetBinContent(5,Boras.meanTempEveryYear);
	h3b->SetBinContent(6,Falun.meanTempEveryYear);
	h3b->SetBinContent(7,Falster.meanTempEveryYear);
	h3b->SetBinContent(8,Umea.meanTempEveryYear);
	h3b->SetBinContent(9,Karl.meanTempEveryYear);
	h3b->SetBinContent(10,Visby.meanTempEveryYear);

	//hs->Add(h3b);
	h3b->Draw("b same");
   
	TH1F *h2b = new TH1F("h2b","h2b",10,0,10);
	h2b->SetFillColor(kBlue);
	h2b->SetBarWidth(0.2);
	h2b->SetBarOffset(0.7);
	h2b->SetStats(0);
	h2b->SetBinContent(1,Soder.warmAndCold[2]);	
	h2b->SetBinContent(2,Upp.warmAndCold[2]);
	h2b->SetBinContent(3,Lund.warmAndCold[2]);
	h2b->SetBinContent(4,Lule.warmAndCold[2]);
	h2b->SetBinContent(5,Boras.warmAndCold[2]);
	h2b->SetBinContent(6,Falun.warmAndCold[2]);
	h2b->SetBinContent(7,Falster.warmAndCold[2]);
	h2b->SetBinContent(8,Umea.warmAndCold[2]);
	h2b->SetBinContent(9,Karl.warmAndCold[2]);
	h2b->SetBinContent(10,Visby.warmAndCold[2]);
	//hs->Add(h2b);
	h2b->Draw("b same");
   	
	leg->AddEntry(h1b, "Warmest year", "F");
	leg->AddEntry(h2b, "Coldest year", "F");
	leg->AddEntry(h3b, "Mean temperature using all data", "F");
	
	//hs->Draw("nostackb");
	//hs->GetXaxis()->SetNdivisions(-10);
	leg->Draw();
}
