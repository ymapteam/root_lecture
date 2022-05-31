// plot_nice_allskymap.C

void plot_nice_allskymap(){
  gStyle->SetOptStat(0);
  gStyle->SetPalette(62);

  // Open TTree file
  TFile *file = new TFile("allsky_photons_1GeV.root", "READ");
  // Get object of tree from file
  TTree *photontree = (TTree*)file->Get("photontree");
  
  TCanvas *can = new TCanvas("canvas", "canvas", 800, 400);
  can->Divide(2,2);
  
  // Draw histogram with selection cut option
  can->cd(1);
  photontree->Draw("B:-L>>hist_galactic(180, -180, 180, 90, -90, 90)", "ZENITH_ANGLE<100", "COLZ");
  can->cd(1)->SetFrameFillColor(kBlack);
  can->cd(1)->SetFrameFillStyle(1001);

  // Get histogrm drawn just now
  TH2F* hist_galactic = (TH2F*)gDirectory->Get("hist_galactic");

  // Draw with Z-axis in log scale
  can->cd(2);
  hist_galactic->Draw("COLZ");
  can->cd(2)->SetFrameFillColor(kBlack);
  can->cd(2)->SetFrameFillStyle(1001);
  can->cd(2)->SetLogz();  
  
  // Draw with maximal limit
  can->cd(3);
  TH2F* hist_galactic_max50 = (TH2F*)hist_galactic->Clone("hist_galactic_max50");
  hist_galactic_max50->SetMaximum(50.);
  hist_galactic_max50->Draw("COLZ");
  can->cd(3)->SetFrameFillColor(kBlack);
  can->cd(3)->SetFrameFillStyle(1001);

  // Draw histogram by AITOFF projection
  can->cd(4);
  hist_galactic_max50->Draw("AITOFF");
}
