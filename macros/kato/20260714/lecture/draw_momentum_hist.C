// draw_momentum_hist.C
// stopmu.rootのTTreeからmomentumの1Dヒストグラムを作る
// 実行例:
//   root -l -q draw_momentum_hist.C

#include <iostream>

#include "TCanvas.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"

void draw_momentum_hist(const char* rootfile = "stopmu.root")
{
  TFile* file = TFile::Open(rootfile, "READ");
  if (!file || file->IsZombie()) {
    std::cerr << "ERROR: cannot open " << rootfile << std::endl;
    return;
  }

  TTree* tree = nullptr;
  file->GetObject("stopmu", tree);
  if (!tree) {
    std::cerr << "ERROR: TTree 'stopmu' was not found" << std::endl;
    return;
  }

  TCanvas* c = new TCanvas("c_momentum", "momentum", 800, 600);
  TH1D* h = new TH1D("h_momentum",
                      "Muon momentum;Momentum [MeV/c];Entries",
                      50, 0, 800);

  tree->Draw("momentum>>h_momentum");
  h->Draw();

  c->SaveAs("momentum_hist.png");

  TFile* outfile = new TFile("momentum_hist.root", "RECREATE");
  h->Write();
  c->Write();
  outfile->Close();

  std::cout << "Saved: momentum_hist.png, momentum_hist.root" << std::endl;
  file->Close();
}
