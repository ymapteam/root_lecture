// fitting4.C

void fitting4(){

  // prepare histogram
  int bin_num=10;
  TH1D *h = new TH1D("h", "h;", bin_num, 0, 10);
  for(int i=0; i<400; i++) h->Fill(gRandom->Gaus(5,1.4));
  h->Draw("E");

  // fitting
  TF1 *f = new TF1("f","[0]*x+[1]",0,10);
  h->Fit(f,"L","");

  // show fitted infomation
  cout << endl;
  for(int i=0; i<f->GetNpar(); i++)
    cout << "p["<<i<<"] = " << f->GetParameter(i) << " +- " << f->GetParError(i) << endl;
  cout << endl;  
  cout << "chi2 = " << f->GetChisquare() << endl;
  cout << "chi2/dof = " << f->GetChisquare()/f->GetNDF() << endl;
  
}


