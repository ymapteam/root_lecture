void example02(TString rootfile_path) {
    // Treeを読み込む
    TFile* root_file = TFile::Open(rootfile_path);
    TTree* tree = (TTree*)root_file->Get("tree");

    // branchから値を読み出す準備
    double adc_value;
    tree->SetBranchAddress("adc_value", &adc_value);

    // ヒストグラムの準備
    const int NBINS = 1024;
    const double XMIN = 0;
    const double XMAX = 8192;
    TH1D* hist = new TH1D("hist", "hist", NBINS, XMIN, XMAX);

    // Treeからヒストグラムにデータを入れる
    int n_entries = tree->GetEntries();
    for (int i_entry = 0; i_entry < n_entries; i_entry++) {
        tree->GetEntry(i_entry);
        hist->Fill(adc_value);
    }

    // ヒストグラムをdraw
    hist->Draw();
}