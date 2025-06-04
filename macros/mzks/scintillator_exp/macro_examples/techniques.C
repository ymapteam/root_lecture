// ----------------------- //
// techniques.C -- macro
// Author: K. Mizukoshi
// Date  : May 12 2020
// ----------------------- //

TH1D* make_hist(TString filename="data1"){
    const Int_t nbins = 8192;
    const Double_t min_bin = 0.;
    const Double_t max_bin = 8192.;
    auto hist = new TH1D(filename, filename,
                         nbins, min_bin-0.5, max_bin-0.5);
    const TString data_dir = "../data/";
    Double_t buffer;
    ifstream ifs(data_dir + filename + ".txt");
    while(ifs >> buffer){
        hist->Fill(buffer);
    }
    hist->Rebin(16);
    return hist;
}

int techniques(){

    auto C = new TCanvas();
    // gROOT->SetStyle("ATLAS");

    auto hist1 = make_hist("data1");
    auto hist2 = make_hist("data2");
    auto hist3 = make_hist("data3");

    hist1->SetTitle("Canvas1;Amplitude (ADC ch.);Counts/bins");
    hist3->SetTitle("Canvas2;Amplitude (ADC ch.);Counts/bins");


    C->Divide(2,1);
    auto c1 = C->cd(1); // ititial canvas id is 1
               //
    hist1->Draw();
    hist2->SetLineColor(kRed+2);
    hist2->Draw("same");

    c1->SetLogy();
    c1->SetGridx();
    c1->BuildLegend();

    auto c2 = C->cd(2);
    hist3->Draw();

    C->SaveAs("./hists.pdf");

    return 0;

}

