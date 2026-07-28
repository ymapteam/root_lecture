// draw_momentum_hist_cut.C
// cutをかけてmomentumの1Dヒストグラムを作る
// 実行例:
//   root -l -q draw_momentum_hist_cut.C

#include <iostream>

#include "TCanvas.h"
#include "TCut.h"
#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"

void draw_momentum_hist_cut(const char* rootfile = "stopmu.root")
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

  TCanvas* c = new TCanvas("c_momentum_cut", "momentum with cut", 800, 600);
  TH1D* h = new TH1D("h_momentum_cut",
                      "Muon momentum with cut;Momentum [MeV/c];Entries",
                      50, 0, 800);

  // cut例：かなり下向きで、上側から入ってくるイベント
  TCut cut = "dir_z < -0.8 && pos_z > 0";
  tree->Draw("momentum>>h_momentum_cut", cut);
  h->Draw();

  c->SaveAs("momentum_hist_cut.png");

  TFile* outfile = new TFile("momentum_hist_cut.root", "RECREATE");
  h->Write();
  c->Write();
  outfile->Close();

  std::cout << "Cut  : " << cut.GetTitle() << std::endl;
  std::cout << "Saved: momentum_hist_cut.png, momentum_hist_cut.root" << std::endl;
  file->Close();
}
