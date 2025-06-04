// --------------------- //
// hist_2d -- root macro
// an example to make 2D
// histogram
// --------------------- //
void hist_2d(){

    const Int_t nbins_x = 100;
    const Double_t min_bin_x = -10.;
    const Double_t max_bin_x =  10.;

    const Int_t nbins_y = 100;
    const Double_t min_bin_y = -10.;
    const Double_t max_bin_y =  10.;

    auto hist = new TH2D("hist", "hist", 
                         nbins_x, min_bin_x, max_bin_x, 
                         nbins_y, min_bin_y, max_bin_y);

    TRandom r;
    for(int i=0;i<100000000;++i){
        double x = r.Gaus(4, 3);
        double y = r.Gaus(-1, 2);
        hist->Fill(x, y);
    }

    hist->Draw("colz");
}
