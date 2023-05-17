// histogram_2D.C

void histogram_2D(){
    // Construct a 2D histogram
    const Int_t NBIN_L = 30; 
    const Int_t L_MIN = -180;
    const Int_t L_MAX = 180; 
    const Int_t NBIN_B = 15; 
    const Int_t B_MIN = -90;
    const Int_t B_MAX = 90;

    TH2D* hist = new /*ここを変えて*/("hist_2D", "Sky map;-L[deg];B[deg]", NBIN_L, /*ここを変えて*/, /*ここを変えて*/, /*ここを変えて*/, /*ここを変えて*/, /*ここを変えて*/);

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
            hist->Fill(/*ここを変えて*/, /*ここを変えて*/);
        }
    }
  
    // Construct a canvas
    TCanvas* can = new TCanvas("can", "All-sky photons", 1800, 600);
    // Divide the canvas into 6 pads
    can->Divide(3, 2);
    gStyle->SetOptStat(0);

    // Draw the histogram with some different style options
    can->cd(1);
    hist->Draw("COLZ");
    can->cd(2);
    hist->Draw("TEXT");
    can->cd(3);
    hist->Draw(/*ここを変えて*/);
    can->cd(4);
    hist->Draw(/*ここを変えて*/);    
    can->cd(5);
    hist->Draw("CANDLE");
    can->cd(6);
    hist->Draw(/*ここを変えて*/);    
}
