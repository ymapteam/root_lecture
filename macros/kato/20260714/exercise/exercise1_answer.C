// Exercise 1 Answer
// stopmu.root の momentum branch だけを書き出し、
// stopmu_mom.root として保存する。

#include <iostream>
#include "TFile.h"
#include "TTree.h"

void exercise1_answer()
{
    // 入力ROOTファイルを開く
    TFile *input_file = TFile::Open("stopmu.root", "READ");

    if (!input_file || input_file->IsZombie()) {
        std::cerr << "Error: stopmu.root could not be opened." << std::endl;
        return;
    }

    // stopmu TTreeを取得する
    TTree *input_tree = nullptr;
    input_file->GetObject("stopmu", input_tree);

    if (!input_tree) {
        std::cerr << "Error: TTree 'stopmu' was not found." << std::endl;
        input_file->Close();
        return;
    }

    // 全Branchを無効化してから、momentumだけを有効化する
    input_tree->SetBranchStatus("*", 0);
    input_tree->SetBranchStatus("momentum", 1);

    // 出力ROOTファイルを作る
    TFile *output_file = TFile::Open("stopmu_mom.root", "RECREATE");

    if (!output_file || output_file->IsZombie()) {
        std::cerr << "Error: stopmu_mom.root could not be created." << std::endl;
        input_file->Close();
        return;
    }

    // 有効になっているBranchだけを全Entryコピーする
    TTree *output_tree = input_tree->CloneTree(-1);
    output_tree->SetName("stopmu");
    output_tree->SetTitle("stopmu tree containing only momentum");

    output_tree->Write();
    output_file->Close();
    input_file->Close();

    std::cout << "Created stopmu_mom.root" << std::endl;
}
