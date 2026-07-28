// Exercise 1
// stopmu.root の momentum branch だけを書き出し、
// stopmu_mom.root として保存しよう。

#include <iostream>
#include "TFile.h"
#include "TTree.h"

void exercise1_write_me()
{
    // 1. 入力ROOTファイルを開く
    TFile *input_file = /* WRITE ME */;

    if (!input_file || input_file->IsZombie()) {
        std::cerr << "Error: stopmu.root could not be opened." << std::endl;
        return;
    }

    // 2. stopmu という名前のTTreeを取得する
    TTree *input_tree = nullptr;
    input_file->GetObject(/* WRITE ME */, input_tree);

    if (!input_tree) {
        std::cerr << "Error: TTree 'stopmu' was not found." << std::endl;
        input_file->Close();
        return;
    }

    // 3. いったん全Branchを無効化する
    input_tree->SetBranchStatus(/* WRITE ME */, /* WRITE ME */);

    // 4. momentum Branchだけを有効化する
    input_tree->SetBranchStatus(/* WRITE ME */, /* WRITE ME */);

    // 5. 出力ROOTファイルを作る
    TFile *output_file = /* WRITE ME */;

    // 6. 有効なBranchだけを含むTTreeをコピーする
    TTree *output_tree = input_tree->CloneTree(/* WRITE ME */);
    output_tree->SetName("stopmu");
    output_tree->SetTitle("stopmu tree containing only momentum");

    // 7. TTreeを書き込み、ファイルを閉じる
    output_tree->Write();
    output_file->Close();
    input_file->Close();

    std::cout << "Created stopmu_mom.root" << std::endl;
}
