// --------------------- //
// hist_3d -- root macro
// an example to make 2D
// histogram
// --------------------- //
void hist_3d(){

    const Int_t nbins_x = 100;
    const Double_t min_bin_x = -10.;
    const Double_t max_bin_x =  10.;

    const Int_t nbins_y = 100;
    const Double_t min_bin_y = -10.;
    const Double_t max_bin_y =  10.;


    auto hist = new TH3D("hist", "hist", 
                         nbins_x, min_bin_x, max_bin_x, 
                         nbins_y, min_bin_y, max_bin_y,
                         nbins_y, min_bin_y, max_bin_y);

    TRandom r;
    for(int i=0;i<10000;++i){
        double x = r.Gaus(4, 3);
        double y = r.Gaus(-1, 2);
        double z = r.Gaus(-1, 2);
        hist->Fill(x, y, z);
    }

    hist->Draw();
}
