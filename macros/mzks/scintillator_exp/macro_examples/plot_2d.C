// ------------------------- //
// plot_2d -- root macro
// to show 2D plot for 
// 2 variable correations
// ------------------------- //

void plot_2d(){

    const Int_t nbin = 100;
    const Double_t min_bin = -5.;
    const Double_t max_bin = 5.;

    auto hist1 = new TH1D("h1", "X", nbin, min_bin, max_bin);
    auto hist2 = new TH1D("h2", "Y", nbin, min_bin, max_bin);
    auto hist_2d = new TH2D("h2d", "h2d", nbin, min_bin, max_bin,
                                          nbin, min_bin, max_bin);

    TRandom r;
    for(int i=0;i<100000;++i){
        Double_t x = r.Gaus(1, 0.6);
        Double_t y = x + r.Gaus(-2, 0.4);
        //Double_t y = 1 + r.Gaus(-2, 0.8);

        hist1->Fill(x);
        hist2->Fill(y);
        hist_2d->Fill(x, y);
    }

    auto C = new TCanvas();
    C->Divide(2,1);
    auto c1 = C->cd(1);
    hist1->Draw();
    hist2->SetLineColor(kRed+2);
    hist2->Draw("same");
    c1->BuildLegend();
    hist1->SetTitle(";Value;Counts/bin");

    auto c2 = C->cd(2);
    hist_2d->Draw("colz");
    hist_2d->SetTitle(";Value X;Value Y");
}
