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

int answer1(){

    gROOT->SetStyle("ATLAS");

    auto hist1 = get_histogram("../data/gamma_1_0MeV_10000_0.root");
    auto hist2 = get_histogram("../data/gamma_1_5MeV_10000_0.root");
    auto hist3 = get_histogram("../data/gamma_2_0MeV_10000_0.root");

    hist3->SetLineColor(kBlack);
    hist3->Draw();
    hist2->SetLineColor(kBlue);
    hist2->Draw("same");
    hist1->SetLineColor(kRed);
    hist1->Draw("same");

    auto graph = new TGraphErrors();

    auto func1 = new TF1("func1", "gaus(0)");
    func1->SetParameter(1, 8500);
    hist1->Fit("func1","","",8000,9000);
    graph->SetPoint(0, func1->GetParameter(1), 1.0);
    graph->SetPointError(0, func1->GetParError(1), 0);

    auto func2 = new TF1("func2", "gaus(0)");
    func2->SetParameter(1, 12500);
    hist2->Fit("func2","","",12000,13000);
    graph->SetPoint(1, func2->GetParameter(1), 1.5);
    graph->SetPointError(1, func2->GetParError(1), 0);

    auto func3 = new TF1("func3", "gaus(0)");
    func3->SetParameter(1, 17000);
    hist3->Fit("func2","","",16000,18000);
    graph->SetPoint(2, func3->GetParameter(1), 2.0);
    graph->SetPointError(2, func3->GetParError(1), 0);

    auto C = new TCanvas("AP");

    auto func_pol = new TF1("func_pol", "pol1");
    func_pol->SetParameter(0, 0);
    func_pol->SetParameter(1, 1.e-4);
    graph->Fit("func_pol", "L", "", 7000, 20000);

    graph->Draw();

    return 0;
}
