// scan_stopmu_tree.C
// stopmu.rootのTTreeを読み、CLIに表示するマクロ
// 実行例:
//   root -l -q scan_stopmu_tree.C

#include <algorithm>
#include <iostream>

#include "TFile.h"
#include "TTree.h"

void scan_stopmu_tree(const char* rootfile = "stopmu.root",
                      Long64_t nshow = 10)
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

  tree->Print();
  tree->Scan("entry_id:momentum:dir_x:dir_y:dir_z:pos_x:pos_y:pos_z:momentum_GeV:r_entry", "", "", nshow);

  Int_t entry_id = 0;
  Float_t momentum = 0, dir_x = 0, dir_y = 0, dir_z = 0;
  Float_t pos_x = 0, pos_y = 0, pos_z = 0;
  Float_t momentum_GeV = 0, r_entry = 0;

  tree->SetBranchAddress("entry_id", &entry_id);
  tree->SetBranchAddress("momentum", &momentum);
  tree->SetBranchAddress("dir_x", &dir_x);
  tree->SetBranchAddress("dir_y", &dir_y);
  tree->SetBranchAddress("dir_z", &dir_z);
  tree->SetBranchAddress("pos_x", &pos_x);
  tree->SetBranchAddress("pos_y", &pos_y);
  tree->SetBranchAddress("pos_z", &pos_z);
  tree->SetBranchAddress("momentum_GeV", &momentum_GeV);
  tree->SetBranchAddress("r_entry", &r_entry);

  const Long64_t nentries = tree->GetEntries();
  const Long64_t nloop = std::min(nentries, nshow);

  std::cout << "\nFirst " << nloop << " entries by GetEntry():\n";
  for (Long64_t i = 0; i < nloop; i++) {
    tree->GetEntry(i);
    std::cout << "entry=" << entry_id
              << "  momentum=" << momentum << " MeV/c"
              << "  dir=(" << dir_x << ", " << dir_y << ", " << dir_z << ")"
              << "  pos=(" << pos_x << ", " << pos_y << ", " << pos_z << ") cm"
              << "  r=" << r_entry << " cm"
              << std::endl;
  }

  file->Close();
}
