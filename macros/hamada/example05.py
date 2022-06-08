import ROOT

# RDataFrameでTreeを読み込む
df = ROOT.RDataFrame('tree', 'rootfiles/data1.root')

# RDataFrameからTH1Dを作成する
hist = df.Filter('adc_value > 1000').Histo1D('adc_value')

# histをdraw
hist.Draw()