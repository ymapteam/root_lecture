// histogram_1D_zenith.C

void histogram_1D_zenith(){
    // Construct a 1D histogram
    const Int_t NBIN_ZENITH = 100; 
    const Int_t ZENITH_MIN = 0;
    const Int_t ZENITH_MAX = 180; 
    TH1D* hist = new TH1D("hist_1D_zenith", "Zenith angle;[deg];[events]", NBIN_ZENITH, ZENITH_MIN, ZENITH_MAX);
    // Make the histogram fancy
    hist->SetFillStyle(3001);
    hist->SetFillColor(kRed);
    hist->SetLineColor(kRed);
    hist->SetLineWidth(2);

    // Open input file
    ifstream ifs("../lat-data/allsky_photons.dat");
    // Check if input file is open
    if(!ifs.is_open()){
        cout << "Input file is not opened!" << endl;
        return 0;
    } 
    // Fill the values to the histogram
    Double_t energy, l, b, zenith, azimuth, time;
    while(ifs >> energy >> l >> b >> zenith >> azimuth >> time){
        hist->Fill(zenith);
    }
  
    // Construct a canvas
    TCanvas* can = new TCanvas("can", "All-sky photons");
    // Draw the histogram
    can->cd();
    hist->Draw();

}
