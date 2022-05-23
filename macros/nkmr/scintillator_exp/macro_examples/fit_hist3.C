// fit_hist3.C

void fit_hist3(){

  // Define Range and Num of bin of histogram
  const int MCACh = 8192;
  const double HistMin = 0.;
  const double HistMax = 8192.;

  TH1D* hist = new TH1D("hist", "hist", MCACh, HistMin-0.5, HistMax-0.5);

  double BufferValue;
  ifstream ifs("../data/data3.txt");
  while(ifs >> BufferValue){
    hist->Fill(BufferValue);
  }

  const int rebin_factor=8;
  hist->Rebin(rebin_factor);
  hist->SetTitle(Form(";ADC channel;Counts/%dch",rebin_factor));
  hist->SetMaximum(400);
  hist->Draw();

  // fitting
  TF1 *func = new TF1("func", "gaus(0)+[3]+x*[4]", HistMin, HistMax);
  func->SetParameters(200, 1500, 100, 200, -0.1);
  hist->Fit(func,"L","same",1100,2000);
  cout << ":-) chi2/dof = " << func->GetChisquare()/func->GetNDF() << endl;
  
}

