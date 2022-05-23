// ----------------------- //
// draw_hist2.C -- macro
// Author: K. Mizukoshi
// Date  : May 12 2020
// ----------------------- //

int draw_hist2(){

    gROOT->SetStyle("ATLAS");
	
	// Define Range and Num of bin of histogram
	const int MCACh = 8192;
	const double HistMin = 0.;
	const double HistMax = 8192.;

	TH1D* hist = new TH1D("hist", "hist", MCACh, HistMin-0.5, HistMax-0.5);

	double BufferValue;
	ifstream ifs("../data/data1.txt");
	while(ifs >> BufferValue){
		hist->Fill(BufferValue);
	}

    hist->Rebin(16);

	hist->SetTitle(";ADC channel;Counts/16ch");
	hist->Draw();

	return 0;
}
