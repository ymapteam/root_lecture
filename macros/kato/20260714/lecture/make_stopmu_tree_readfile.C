// make_stopmu_tree_readfile.C
// datファイルをそのままTTreeに読み込む、一番短い例
// 実行例:
//   root -l -q make_stopmu_tree_readfile.C

#include "TFile.h"
#include "TTree.h"
#include <iostream>

void make_stopmu_tree_readfile(const char *input = "stopmu.dat",
                               const char *output = "stopmu_readfile.root") {
  TFile *file = new TFile(output, "RECREATE");
  if (!file || file->IsZombie()) {
    std::cerr << "ERROR: cannot create " << output << std::endl;
    return;
  }

  TTree *tree = new TTree("stopmu", "stop muon vector");

  // datの7列を、そのままbranchにする
  // /F は Float_t 型という意味
  Long64_t nread = tree->ReadFile(
      input, "momentum/F:dir_x/F:dir_y/F:dir_z/F:pos_x/F:pos_y/F:pos_z/F");

  tree->Write();
  file->Close();

  std::cout << "Created: " << output << std::endl;
  std::cout << "Tree name: stopmu" << std::endl;
  std::cout << "Entries  : " << nread << std::endl;
}
