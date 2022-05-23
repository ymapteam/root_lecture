// fit_hist2.C

void fit_hist2(){

  // Define Range and Num of bin of histogram
  const int MCACh = 8192;
  const double HistMin = 0.;
  const double HistMax = 8192.;

  TH1D* hist = new TH1D("hist", "hist", MCACh, HistMin-0.5, HistMax-0.5);

  double BufferValue;
  ifstream ifs("../data/data2.txt");
  while(ifs >> BufferValue){
    hist->Fill(BufferValue);
  }

  const int rebin_factor=8;
  hist->Rebin(rebin_factor);
  hist->SetTitle(Form(";ADC channel;Counts/%dch",rebin_factor));
  hist->Draw();

  // fitting
  TF1 *func1 = new TF1("func1", "gaus(0)", HistMin, HistMax);
  func1->SetParameters(30, 5600, 200);
  hist->Fit(func1,"L","same",5200,6500);
  cout << "(-->) chi2/dof = " << func1->GetChisquare()/func1->GetNDF() << endl;

  TF1 *func2 = new TF1("func2", "gaus(0)", HistMin, HistMax);
  func2->SetParameters(300, 2400, 100);
  hist->Fit(func2,"L","",2000,2800);
  cout << "(<--) chi2/dof = " << func2->GetChisquare()/func2->GetNDF() << endl;
  func1->Draw("same");
  
}

