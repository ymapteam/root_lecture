// ----------------------- //
// sum_counts.C -- macro
// Author: K. Mizukoshi, S.Sakurai
// Date  : May 29 2024
// ----------------------- //

int sum_counts()
{

	// Define Range and Num of bin of histgram
	const int MCACh = 8192;
	const double HistMin = 0.;
	const double HistMax = 8192.;
	const double IntMin = 2500;
	const double IntMax = 3500;
	double CountSum = 0;

	// Create Histgram
	TH1D *hist = new TH1D("hist", "hist", MCACh, HistMin - 0.5, HistMax - 0.5);
	double BufferValue;
	ifstream ifs("../../../mzks/scintillator_exp/data/data1.txt");
	while (ifs >> BufferValue)
	{
		hist->Fill(BufferValue);
	}

	hist->Rebin(8);

	for (int i = 0; i < hist->GetNbinsX(); i++)
	{
		if ((hist->GetBinCenter(i) >= IntMin) && (hist->GetBinCenter(i) <= IntMax))
		{
			CountSum += hist->GetBinContent(i);
		}
	}

	cout << "Integration from " << IntMin << " to " << IntMax << endl;
	cout << "CountSum = " << CountSum << endl;

	hist->SetTitle(";ADC channel;Counts/ch");
	hist->Draw();

	return 0;
}
