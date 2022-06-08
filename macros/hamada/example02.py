import ROOT

# Treeを読み込む
root_file_path = "rootfiles/data1.root"
root_file = ROOT.TFile.Open(root_file_path)
tree = root_file.Get("tree")

# ヒストグラムの準備
NBINS = 1024
XNIN = 0
XMAX = 8192
hist = ROOT.TH1D("hist", "hist", NBINS, XNIN, XMAX)

# Treeからヒストグラムにデータを入れる
n_entries = tree.GetEntries()
for i_entry in range(n_entries):
    tree.GetEntry(i_entry)
    hist.Fill(tree.adc_value)
    
# ヒストグラムをdraw
hist.Draw()