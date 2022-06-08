import ROOT

# Treeを読み込む
root_file_path = "rootfiles/data1.root"
root_file = ROOT.TFile.Open(root_file_path)
tree = root_file.tree # Pythonっぽい

# ヒストグラムの準備
NBINS = 1024
XNIN = 0
XMAX = 8192
hist = ROOT.TH1D("hist", "hist", NBINS, XNIN, XMAX)

# Treeからヒストグラムにデータを入れる
n_entries = tree.GetEntries()
for event in tree: # pythonっぽい
    if event.adc_value > 1000:
        hist.Fill(event.adc_value)
    
# ヒストグラムをdraw
hist.Draw()