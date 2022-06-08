void example01(TString data_path, TString out_file_path){
    // TTreeを準備
    TTree* tree = new TTree("tree", "tree");
    double adc_value;
    tree->Branch("adc_value", &adc_value, "adc_value/D");

    // treeにデータを読み込む
    ifstream ifs(data_path);
    while(ifs >> adc_value){
        tree->Fill();
    }

    // treeを保存
    TFile* out_file = new TFile(out_file_path, "recreate");
    tree->Write();
    out_file->Close();
}