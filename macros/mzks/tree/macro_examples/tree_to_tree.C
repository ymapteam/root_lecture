// --------------------------- //
// tree_to_tree.C
// Tree reading example
// Author : Keita Mizukoshi
// 2024 Jun. 11
// --------------------------- //


int tree_to_tree(TString filename="../data/gamma_1_5MeV_10000_0.root"){

    auto file = TFile::Open(filename);
    auto tree = dynamic_cast<TTree*>(file->Get("tree"));

    Int_t           nHit;
    Double_t        total_adc;
    vector<double>  *tdc = 0;
    vector<double>  *adc = 0;
    vector<int>     *detector_id = 0;
    vector<int>     *particle_id = 0;

    tree->SetBranchAddress("nHit", &nHit);
    tree->SetBranchAddress("total_adc", &total_adc);
    tree->SetBranchAddress("tdc", &tdc);
    tree->SetBranchAddress("adc", &adc);
    tree->SetBranchAddress("detector_id", &detector_id);
    tree->SetBranchAddress("particle_id", &particle_id);

    ULong64_t n_entries = tree->GetEntries();

    auto new_file = new TFile("new_file.root", "RECREATE");
    auto new_tree = new TTree("new_tree", "Tree title");

    Double_t calibrated_adc;
    new_tree->Branch("calibrated_adc", &calibrated_adc);

    constexpr double calibration_factor = 1.0; // dummy
                                               //
    for(ULong64_t i_entry=0; i_entry<n_entries; ++i_entry){
        tree->GetEntry(i_entry);

        if(nHit != 1) continue;

        calibrated_adc = total_adc * calibration_factor;
        new_tree->Fill();
    }
    new_tree->Write();
    new_file->Close();

    return 0;
}
