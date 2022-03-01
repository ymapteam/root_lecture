
void first_hist(){

    int total_bin = 10;
    int min_bin = 0;
    int max_bin = 10;
    TH1D* hist = new TH1D("hist", "hist", total_bin, min_bin, max_bin);

    hist->Fill(2);
    hist->Fill(1);
    hist->Fill(2);
    hist->Fill(3);
    hist->Fill(4);

    hist->Draw();

}
