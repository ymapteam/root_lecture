// ----------------------- //
// scale_hists.C -- macro
// Author: K. Mizukoshi, S. Sakurai
// Date  : May 29 2024
// ----------------------- //

TH1D* make_hist(TString filename = "data1"){

    gROOT->SetStyle("ATLAS");
	const int MCACh = 8192;
	const double HistMin = 0.;
	const double HistMax = 8192.;

	TH1D* hist = new TH1D(filename, filename , MCACh, HistMin-0.5, HistMax-0.5);

    const TString data_dir = "../../../mzks/scintillator_exp/data/";
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

int scale_hists(){

    TH1D* hist1 = make_hist("data1");
    TH1D* hist2 = make_hist("data2");
    TH1D* hist3 = make_hist("data3");

    hist1->Draw("hist");
	hist2->Scale(hist1->GetEntries()/hist2->GetEntries());
    hist2->SetLineColor(kBlue);
    hist2->Draw("hist sames");
	hist3->Scale(hist1->GetEntries()/hist3->GetEntries());
    hist3->SetLineColor(kRed);
    hist3->Draw("hist sames");

    return 0;
}
