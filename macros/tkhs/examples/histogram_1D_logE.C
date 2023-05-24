// histogram_1D_logE.C

void histogram_1D_logE(){
    // Construct a 1D histogram
    const Int_t NBIN_ENERGY = 100; 
    const Int_t ENERGY_MIN = 300; //100 MeV
    const Int_t ENERGY_MAX = 100000; //100 GeV
    TH1D* hist = new TH1D("hist_1D", "Count spectrum;log_{10}(Energy[MeV]);[events]", NBIN_ENERGY, log10(/*ここを変えて*/), log10(/*ここを変えて*/));
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
        hist->Fill(/*ここを変えて*/);
    }
  
    // Construct a canvas
    TCanvas* can = new TCanvas("can", "All-sky photons");
    // Draw the histogram
    can->cd();
    hist->Draw();
    can->SetLogy();
}
