int answer2(TString filename="../data/gamma_1_5MeV_10000_*.root"){

    auto tree = new TChain("tree", "title");
    tree->Add(filename);

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

    Double_t energy;
    new_tree->Branch("energy", &energy);

    constexpr double p0 = -5.43565e-04;
    constexpr double p1 = 1.18647e-04;
                                               //
    for(ULong64_t i_entry=0; i_entry<n_entries; ++i_entry){
        tree->GetEntry(i_entry);

        if(nHit!=1) continue;

        energy = total_adc * p1 + p0;
        new_tree->Fill();
    }
    new_tree->Write();
    new_file->Close();

    return 0;
}
