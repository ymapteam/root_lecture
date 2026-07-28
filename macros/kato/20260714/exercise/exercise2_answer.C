// Exercise 2 Answer
// stopmu.root の pos_x と pos_y を使って、
// 2次元ヒストグラムを描く。

#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH2D.h"
#include "TCanvas.h"

void exercise2_answer()
{
    // ROOTファイルを開く
    TFile *file = TFile::Open("stopmu.root", "READ");

    if (!file || file->IsZombie()) {
        std::cerr << "Error: stopmu.root could not be opened." << std::endl;
        return;
    }

    // stopmu TTreeを取得する
    TTree *tree = nullptr;
    file->GetObject("stopmu", tree);

    if (!tree) {
        std::cerr << "Error: TTree 'stopmu' was not found." << std::endl;
        file->Close();
        return;
    }

    // x軸をpos_x、y軸をpos_yとする2次元ヒストグラム
    // 範囲は例として -2000 cm ～ 2000 cm に設定
    TH2D *h_pos_xy = new TH2D(
        "h_pos_xy",
        "Muon position;pos_x [cm];pos_y [cm]",
        100, -2000.0, 2000.0,
        100, -2000.0, 2000.0
    );

    TCanvas *canvas = new TCanvas(
        "canvas_pos_xy",
        "pos_x vs pos_y",
        800,
        700
    );

    // TTree::Drawの式は「y:x」
    // "goff"を付けると、ここでは自動描画せずヒストグラムへのFillだけを行う
    tree->Draw("pos_y:pos_x>>h_pos_xy", "", "goff");

    // COLZ: 2次元分布を色で表示し、右側にカラースケールを出す
    h_pos_xy->Draw("COLZ");

    canvas->Update();
}
