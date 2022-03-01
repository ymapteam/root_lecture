// -------------------------------- //
// draw_hists_not_good.C -- macro
// Author: K. Mizukoshi
// Date  : May 13 2020
// -------------------------------- //

int draw_hists_not_good(){

    gROOT->SetStyle("ATLAS");
	const int MCACh = 8192;
	const double HistMin = 0.;
	const double HistMax = 8192.;

	TH1D* hist1 = new TH1D("hist1", "hist1" , MCACh, HistMin-0.5, HistMax-0.5);
	TH1D* hist2 = new TH1D("hist2", "hist2" , MCACh, HistMin-0.5, HistMax-0.5);

	double BufferValue1;
	ifstream ifs1("../data/data1.txt");
	while(ifs1 >> BufferValue1){
		hist1->Fill(BufferValue1);
	}
	double BufferValue2;
	ifstream ifs2("../data/data2.txt");
	while(ifs2 >> BufferValue2){
		hist2->Fill(BufferValue2);
	}

    hist1->Rebin(16);
    hist2->Rebin(16);
	hist1->SetTitle(";ADC channel;Counts/16ch");
	hist1->Draw();
    hist2->SetLineColor(kBlue);
    hist2->Draw("same");
	return 0;
}

