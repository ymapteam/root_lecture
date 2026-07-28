ROOT講習 第4回 stopmu用マクロ
0.stopmu.dat

1. 単にテキストファイルを読む場合
   root -l -q make_stopmu_tree_readfile.C
   出力: stopmu_readfile.root

2. 処理を入れてTTreeを作る場合
   root -l -q make_stopmu_tree.C
   出力: stopmu.root

3. TreeをCLIに表示する
   root -l -q scan_stopmu_tree.C

4. momentumの1Dヒストグラムを作る
   root -l -q draw_momentum_hist.C
   出力: momentum_hist.png, momentum_hist.root

5. cutをかけてmomentumの1Dヒストグラムを作る
   root -l -q draw_momentum_hist_cut.C
   出力: momentum_hist_cut.png, momentum_hist_cut.root
