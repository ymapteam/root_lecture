// fit_hist1_v2.C

void fit_hist1_v2(){

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

  const int rebin_factor=8;
  hist->Rebin(rebin_factor);
  hist->SetTitle(Form(";ADC channel;Counts/%dch",rebin_factor));
  hist->Draw();

  // fitting
  TF1 *func = new TF1("func", "gaus(0)", HistMin, HistMax);
  hist->Fit(func,"L","",2500,3500);
  cout << "(^o^) chi2/dof = " << func->GetChisquare()/func->GetNDF() << endl;
    
}

