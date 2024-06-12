// ------------------------------ //
// cut.C
// Tree reading example with cut
// Author : Keita Mizukoshi
// 2024 Jun. 11
// ------------------------------ //


int cut(TString filename="../data/gamma_1_5MeV_10000_0.root"){

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

    constexpr int nbin = 200;
    constexpr double min_bin = 0;
    constexpr double max_bin = 20000;
    auto hist = new TH1D("hist", "hist", nbin, max_bin, min_bin);
    hist->SetTitle(";ADC counts;Counts/100 ADC");

    constexpr int target_detector_id = 1;
    for(ULong64_t i_entry=0; i_entry<n_entries; ++i_entry){
        tree->GetEntry(i_entry);

        if(nHit == 0) continue;
        
        for(auto i=0;i<detector_id->size();++i){
            if(detector_id->at(i) == target_detector_id){
                hist->Fill(adc->at(i));
            }
        }

    }
    hist->Draw();

    return 0;
}
