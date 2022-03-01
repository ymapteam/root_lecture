// ---------------------------- //
// fit_hagure.C
//      root macro
// Author: Keita Mizukoshi
// Date  : May 13 2020
// Usate : in macro directory,
// > root -l fit_hagure.C
// ---------------------------- //

void fill_from_file(TH1D* hist, TString filename = "../data/data1.txt"){

    ifstream ifs(filename);
    int n_escaped_turn;
    while(ifs >> n_escaped_turn){
        hist->Fill(n_escaped_turn);
    }
}

TH1D* fill_from_files(){

    int total_bin = 25;
    int min_bin = 0;
    int max_bin = 25;
    TH1D* hist = new TH1D("hist", "Title", total_bin, min_bin-0.5, max_bin-0.5);
    
    fill_from_file(hist, "../data/data1.txt");
    fill_from_file(hist, "../data/data2.txt");
    fill_from_file(hist, "../data/data3.txt");
    fill_from_file(hist, "../data/data4.txt");
    fill_from_file(hist, "../data/data5.txt");

    return hist;

}

int fit_hagure(){

    gROOT->SetStyle("ATLAS");

    TH1D* hist = fill_from_files();
    hist->Draw("E");
    hist->SetTitle(";n turn which the enemy escaped;Counts/turn");
    // hist->Rebin(2);

    TF1* model_func = new TF1("model_func", 
        "[0]/([1]-1)*TMath::Log([1])*(TMath::Power([1],x)-TMath::Power([1],x+1))",
        -1,20);
    model_func->SetParName(0, "n_trials");
    model_func->SetParName(1, "Prob_remain");
    model_func->SetParameter(0, 37);
    model_func->SetParameter(1, 0.7);

    model_func->SetLineStyle(2);
    model_func->SetLineColor(kRed+3);

    hist->Fit("model_func","L","",-1,25);

    return 0;
}
