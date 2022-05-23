// fitting3.C

void fitting3(){

  // prepare histogram
  int bin_num=10;
  TH1D *h = new TH1D("h", "h;", bin_num, 0, 10);
  for(int i=0; i<90; i++) h->Fill(0);
  for(int i=0; i<100; i++) h->Fill(1);
  // for(int i=2; i<10; i++) h->Fill((double)i);
  h->Draw("E");

  // fitting
  TF1 *f = new TF1("f","[0]*x+[1]",0,10);
  h->Fit(f,"","");
  // h->Fit(f,"L","");
  
}


