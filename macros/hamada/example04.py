import ROOT

# Treeを読み込む
root_file_path = "rootfiles/data1.root"
root_file = ROOT.TFile.Open(root_file_path)
tree = root_file.tree # Pythonっぽい

# ヒストグラムの準備
NBINS = 1024
XMIN = 0
XMAX = 8192

# tree->Draw() の結果をhistという名前のオブジェクトに保存させる
tree.Draw(f"adc_value >> hist({NBINS}, {XMIN}, {XMAX})", "adc_value > 1000")

# histを取ってくる
hist = ROOT.gDirectory.Get("hist")
hist.GetXaxis().SetRangeUser(0, 4000)
hist.Draw()