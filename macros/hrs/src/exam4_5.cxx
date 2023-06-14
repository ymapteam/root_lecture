void exam4_5(){

  int event;
  double Epi, ppi, p_pi[3], Eg1, Eg2, pg1,pg2, p_g1[3],p_g2[3];
  double costheta,inpro;
  
  auto file = new TFile("exam4.root");
  auto tree =(TTree*) file->Get("tree");
  tree->SetBranchAddress("event",&event);
  tree->SetBranchAddress("Epi",&Epi);
  tree->SetBranchAddress("ppi",&ppi);
  tree->SetBranchAddress("p_pi[3]",&p_pi);
  tree->SetBranchAddress("Eg1",&Eg1);
  tree->SetBranchAddress("pg1",&pg1);
  tree->SetBranchAddress("p_g1[3]",&p_g1);
  tree->SetBranchAddress("Eg2",&Eg2);
  tree->SetBranchAddress("pg2",&pg2);
  tree->SetBranchAddress("p_g2[3]",&p_g2);

  gROOT->SetStyle("ATLAS");
  auto hist=new TH1F("hist","hist",100,-1,1);
  auto c1=new TCanvas("c1","",600,400);

  for(int i=0;i<tree->GetEntries();i++){
    tree->GetEntry(i);
    inpro=0;
    for(int j=0;j<3;j++)
      inpro += p_g1[j]*p_g2[j];
    costheta = inpro/pg1/pg2;
    hist->Fill(costheta);
  }
  hist->GetXaxis()->CenterTitle();
  hist->GetYaxis()->CenterTitle();
  hist->SetXTitle("Opening angle cos#theta_{#gamma#gamma}");
  hist->SetYTitle("Counts/ bin");
  hist->Draw("hist");
  
  return;
}
