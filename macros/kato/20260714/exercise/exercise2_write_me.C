// Exercise 2
// stopmu.root の pos_x と pos_y を使って、
// 2次元ヒストグラムを描いてみよう。

#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH2D.h"
#include "TCanvas.h"

void exercise2_write_me()
{
    // 1. ROOTファイルを開く
    TFile *file = /* WRITE ME */;

    if (!file || file->IsZombie()) {
        std::cerr << "Error: stopmu.root could not be opened." << std::endl;
        return;
    }

    // 2. stopmu TTreeを取得する
    TTree *tree = nullptr;
    file->GetObject(/* WRITE ME */, tree);

    if (!tree) {
        std::cerr << "Error: TTree 'stopmu' was not found." << std::endl;
        file->Close();
        return;
    }

    // 3. 2次元ヒストグラムを作る
    //    x軸: pos_x [cm], y軸: pos_y [cm]
    TH2D *h_pos_xy = new TH2D(
        "h_pos_xy",
        "Muon position;pos_x [cm];pos_y [cm]",
        /* WRITE ME */, /* WRITE ME */, /* WRITE ME */,
        /* WRITE ME */, /* WRITE ME */, /* WRITE ME */
    );

    // 4. Canvasを作る
    TCanvas *canvas = new TCanvas(
        "canvas_pos_xy",
        "pos_x vs pos_y",
        /* WRITE ME */,
        /* WRITE ME */
    );

    // 5. TTreeからpos_x, pos_yを読み出してヒストグラムに詰める
    // TTree::Drawでは「y:x」の順番で書く点に注意
    tree->Draw(/* WRITE ME */, /* WRITE ME */, /* WRITE ME */);

    // 6. 色付きで表示する
    h_pos_xy->Draw(/* WRITE ME */);

    canvas->Update();
}
