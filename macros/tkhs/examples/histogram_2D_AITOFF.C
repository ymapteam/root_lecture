// histogram_2D_AITOFF.C

void histogram_2D_AITOFF(){
    // Construct a 2D histogram
    const Int_t NBIN_L = 180; 
    const Int_t L_MIN = -180;
    const Int_t L_MAX = 180; 
    const Int_t NBIN_B = 90; 
    const Int_t B_MIN = -90;
    const Int_t B_MAX = 90;

    TH2D* hist = new TH2D("hist_2D", "Sky map;-L[deg];B[deg]", NBIN_L, L_MIN, L_MAX, NBIN_B, B_MIN, B_MAX);

    // Open input file
    ifstream ifs("../lat-data/allsky_photons.dat");
    // Check if input file is open
    if(!ifs.is_open()){
        cout << "Input file is not opened!" << endl;
        return 0;
    } 
    // Fill the values to the histogram
    Double_t energy, l, b, zenith, azimuth, time;
    Double_t l_fill;
    while(ifs >> energy >> l >> b >> zenith >> azimuth >> time){
        if(zenith<100){
            l_fill = l>180 ? -l+360.:-l;
            hist->Fill(l_fill, b);
        }
    }
  
    // Construct a canvas
    TCanvas* can = new TCanvas("can", "All-sky photons", 1200, 600);
    gStyle->SetOptStat(0);
    // Draw the histogram
    can->cd();
    hist->Draw(/*ここを変えて*/);
    hist->SetMaximum(200);
    gStyle->/*ここを変えて*/;
}
