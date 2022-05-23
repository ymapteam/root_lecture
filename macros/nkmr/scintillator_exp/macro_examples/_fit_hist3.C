// fit_hist3.C

void fit_hist3(){

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
  TF1 *func = new TF1("func", "gaus(0)+[3]*TMath::Exp(-[4]*x)", HistMin, HistMax);
  func->SetParameters(400, 3000, 150, 10, 0.001);
  hist->Fit(func,"L","",2500,3500);
  cout << "(T_T) chi2/dof = " << func->GetChisquare()/func->GetNDF() << endl;

  // draw fitted curves
  TF1 *func1 = new TF1("func1", "gaus(0)", HistMin, HistMax);
  for(int i=0; i<3; i++) func1->SetParameter(i,func->GetParameter(i));
  TF1 *func2 = new TF1("func2", "[0]*TMath::Exp(-[1]*x)", HistMin, HistMax);
  for(int i=0; i<2; i++) func2->SetParameter(i,func->GetParameter(3+i));
  func1->SetLineColor(4);
  func2->SetLineColor(4);
  func1->SetLineStyle(2);
  func2->SetLineStyle(2);
  func1->Draw("same");
  func2->Draw("same");
  
}

