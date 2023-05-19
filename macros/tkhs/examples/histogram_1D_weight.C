// histogram_1D_weight.C

void histogram_1D_weight(){
    // Define your X-axis flexibly
    const Int_t NBIN_ENERGY = 100; 
    const Int_t ENERGY_MIN = 300; //300 MeV
    const Int_t ENERGY_MAX = 100000; //100 GeV
    Double_t xbins[NBIN_ENERGY+1];
    const Double_t LOGE_BINWIDTH = (log10(ENERGY_MAX) - log10(ENERGY_MIN)) / NBIN_ENERGY; // Divide the X-axis by an equivalent width in log-space
    for(int ibin=0; ibin<NBIN_ENERGY; ibin++){
        xbins[ibin] = ENERGY_MIN * pow(10, LOGE_BINWIDTH * ibin);
    }
    xbins[NBIN_ENERGY] = ENERGY_MAX;
    
    // Construct a 1D histogram    
    TH1D* hist = new TH1D("hist_1D", "Energy spectrum;Energy [MeV];EdN [MeV]", NBIN_ENERGY, xbins);
    // Make the histogram fancy
    hist->SetFillStyle(3001);
    hist->SetFillColor(kBlue);
    hist->SetLineColor(kBlue);
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
        hist->/*ここを変えて*/
    }
  
    // Construct a canvas
    TCanvas* can = new TCanvas("can", "All-sky photons");
    // Draw the histogram
    can->cd();
    hist->Draw();
    can->SetLogx();
    can->SetLogy();
}
