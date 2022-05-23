// ----------------------- //
// draw_hists.C -- macro
// Author: K. Mizukoshi
// Date  : May 13 2020
// ----------------------- //

TH1D* make_hist(TString filename = "data1"){

    gROOT->SetStyle("ATLAS");
	const int MCACh = 8192;
	const double HistMin = 0.;
	const double HistMax = 8192.;

	TH1D* hist = new TH1D(filename, filename , MCACh, HistMin-0.5, HistMax-0.5);

    const TString data_dir = "../data/";
	double BufferValue;
	ifstream ifs(data_dir + filename + ".txt");
	while(ifs >> BufferValue){
		hist->Fill(BufferValue);
	}

    hist->Rebin(16);
	hist->SetTitle(";ADC channel;Counts/16ch");
	//hist->Draw();
	return hist;
}

int draw_hists(){

    TH1D* hist1 = make_hist("data1");
    TH1D* hist2 = make_hist("data2");

    hist1->Draw();
    hist2->SetLineColor(kBlue);
    hist2->Draw("same");

    return 0;
}
