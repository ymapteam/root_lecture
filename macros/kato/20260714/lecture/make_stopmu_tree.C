// make_stopmu_tree.C
// datファイルを1行ずつ読み、処理を入れてTTreeを作る例
// 実行例:
//   stopmu.dat
//   root -l -q make_stopmu_tree.C

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

#include "TFile.h"
#include "TTree.h"

void make_stopmu_tree(const char* input = "stopmu.dat",
                      const char* output = "stopmu.root")
{
  std::ifstream fin(input);
  if (!fin.is_open()) {
    std::cerr << "ERROR: cannot open " << input << std::endl;
    return;
  }

  TFile* file = new TFile(output, "RECREATE");
  if (!file || file->IsZombie()) {
    std::cerr << "ERROR: cannot create " << output << std::endl;
    return;
  }

  TTree* tree = new TTree("stopmu", "stop muon vector");

  // datから読む7列
  Float_t momentum = 0;  // [MeV/c]
  Float_t dir_x = 0;
  Float_t dir_y = 0;
  Float_t dir_z = 0;
  Float_t pos_x = 0;     // [cm]
  Float_t pos_y = 0;     // [cm]
  Float_t pos_z = 0;     // [cm]

  // 自分で計算して追加するbranch
  Int_t entry_id = 0;
  Float_t momentum_GeV = 0;  // [GeV/c]
  Float_t r_entry = 0;       // [cm]

  tree->Branch("entry_id", &entry_id, "entry_id/I");
  tree->Branch("momentum", &momentum, "momentum/F");
  tree->Branch("dir_x", &dir_x, "dir_x/F");
  tree->Branch("dir_y", &dir_y, "dir_y/F");
  tree->Branch("dir_z", &dir_z, "dir_z/F");
  tree->Branch("pos_x", &pos_x, "pos_x/F");
  tree->Branch("pos_y", &pos_y, "pos_y/F");
  tree->Branch("pos_z", &pos_z, "pos_z/F");
  tree->Branch("momentum_GeV", &momentum_GeV, "momentum_GeV/F");
  tree->Branch("r_entry", &r_entry, "r_entry/F");

  while (fin >> momentum >> dir_x >> dir_y >> dir_z >> pos_x >> pos_y >> pos_z) {
    // 例：方向ベクトルを念のため規格化する
    const Float_t norm = std::sqrt(dir_x*dir_x + dir_y*dir_y + dir_z*dir_z);
    if (norm > 0) {
      dir_x /= norm;
      dir_y /= norm;
      dir_z /= norm;
    }

    // 例：解析しやすい量を追加で計算して保存する
    momentum_GeV = momentum / 1000.0;
    r_entry = std::sqrt(pos_x*pos_x + pos_y*pos_y + pos_z*pos_z);

    tree->Fill();
    entry_id++;
  }

  tree->Write();
  file->Close();

  std::cout << "Created: " << output << std::endl;
  std::cout << "Tree name: stopmu" << std::endl;
  std::cout << "Entries  : " << entry_id << std::endl;
}
