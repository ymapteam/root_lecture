// ----------------------- //
// use_methods.C -- macro
// Author: K. Mizukoshi
// Date  : May 12 2020
// ----------------------- //

int use_methods(){
	
	// Define Range and Num of bin of histgram
	const int MCACh = 8192;
	const double HistMin = 0.;
	const double HistMax = 8192.;

	// Create Histgram
	TH1D* hist = new TH1D("hist", "hist", MCACh, HistMin-0.5, HistMax-0.5);
	double BufferValue;
	ifstream ifs("../data/data1.txt");
	while(ifs >> BufferValue){
		hist->Fill(BufferValue);
	}

    hist->Rebin(8);

    cout << "Sample Size    : " << hist->GetEntries() << endl;
    cout << "Maximum Value  : " << hist->GetMaximum() << endl;
    cout << "Maximum Bin    : " << hist->GetMaximumBin() << endl;
    cout << "Mean           : " << hist->GetMean() << endl;
    cout << "Standard Dev   : " << hist->GetStdDev() << endl;
    cout << "Mean Error     : " << hist->GetMeanError() << endl;

    cout << "7th Bin content: " << hist->GetBinContent(7) << endl;

	hist->SetTitle(";ADC channel;Counts/ch");
	hist->Draw();

	return 0;
}
