TH1D* get_histogram(TString filename="../data/gamma_1_0MeV_10000_0.root"){
    auto file = TFile::Open(filename);
    auto tree = dynamic_cast<TTree*>(file->Get("tree"));

    constexpr int nbin = 200;
    constexpr double min_bin = 0;
    constexpr double max_bin = 20000;
    TH1D* hist = new TH1D("hist", "hist", nbin, max_bin, min_bin);

    tree->Draw("total_adc>>hist");

    return hist;
}

int make_histogram_from_tree(){

    auto hist1 = get_histogram("../data/gamma_1_0MeV_10000_0.root");
    auto hist2 = get_histogram("../data/gamma_1_5MeV_10000_0.root");
    auto hist3 = get_histogram("../data/gamma_2_0MeV_10000_0.root");

    hist3->SetLineColor(kBlack);
    hist3->Draw();
    hist2->SetLineColor(kBlue);
    hist2->Draw("same");
    hist1->SetLineColor(kRed);
    hist1->Draw("same");

    return 0;
}
