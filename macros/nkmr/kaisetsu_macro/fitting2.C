// fitting2.C

void fitting2(){

  // prepare histogram
  int bin_num=10;
  TH1D *h = new TH1D("h", "h;", bin_num, 0, 10);
  for(int i=0; i<400; i++) h->Fill(gRandom->Gaus(5,1.4));
  h->Draw("E");

  // fitting
  TF1 *f = new TF1("f","[0]*TMath::Exp(-(x-[1])*(x-[1])/[2]/[2])",0,10);
  f->SetParameters(10,5,2);
  h->Fit(f,"L","",0,10);
  
}


