// ----------------------- //
// draw_hist1.C -- macro
// Author: K. Mizukoshi
// Date  : May 12 2020
// Cs-137 data collected
//  by MCA module
// ----------------------- //

int draw_hist1(){
	
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

	hist->SetTitle(";ADC channel;Counts/ch");
	hist->Draw();

	return 0;
}
