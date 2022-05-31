// plot_around_3C279.C

void plot_around_3C279(){
  gStyle->SetOptStat(0);

  // Open TTree file
  TFile *file = new TFile("allsky_photons_300MeV.root", "READ");
  // Get object of tree from file
  TTree *photontree = (TTree*)file->Get("photontree");
  
  TCanvas *can1 = new TCanvas("canvas1", "canvas1", 800, 400);
  can1->Divide(2,2);
  
  // Draw histogram with selection cut option
  can1->cd(1);
  photontree->Draw("log10(ENERGY):(TIME-455675266.)/86400.>>hist_3C279(35, 0, 7, 10, 2.5, 4.5)", "ANGLE_3C279<2 && ZENITH_ANGLE<100", "COLZ");

  // Get histogrm drawn just now
  TH2F* hist_3C279 = (TH2F*)gDirectory->Get("hist_3C279");

  // Draw X-axis projection
  can1->cd(2);
  can1->cd(2)->SetLogy();
  hist_3C279->ProjectionY()->Draw("E");
  
  // Draw Y-axis projection
  can1->cd(3);
  hist_3C279->ProjectionX()->Draw("E");

  TCanvas *can2 = new TCanvas("canvas2", "canvas2", 800, 400);
  can2->Divide(2,2);
  
  // Draw histogram with selection cut option
  can2->cd(1);
  hist_3C279->Draw("COLZ");

  // Draw X-axis profile
  can2->cd(2);
  can2->cd(2)->SetLogy();
  hist_3C279->ProfileY("S")->Draw();
  
  // Draw Y-axis profile
  can2->cd(3);
  hist_3C279->ProfileX()->Draw();
}
