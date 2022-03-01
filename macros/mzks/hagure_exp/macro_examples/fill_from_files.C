void fill_from_file(TH1D* hist, TString filename = "../data/data1.txt"){

    ifstream ifs(filename);
    int n_escaped_turn;
    while(ifs >> n_escaped_turn){
        hist->Fill(n_escaped_turn);
    }
}

void fill_from_files(){

    int total_bin = 10;
    int min_bin = 0;
    int max_bin = 10;
    TH1D* hist = new TH1D("hist", "Title", total_bin, min_bin-0.5, max_bin-0.5);
    
    fill_from_file(hist, "../data/data1.txt");
    fill_from_file(hist, "../data/data2.txt");
    fill_from_file(hist, "../data/data3.txt");
    fill_from_file(hist, "../data/data4.txt");
    fill_from_file(hist, "../data/data5.txt");

    hist->SetTitle(";n turn which the enemy escaped;Counts/turn");
    hist->Draw();

}
