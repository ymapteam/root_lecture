int make_tree_ascii(TString filename="../data/data1.txt"){

    auto file_out = new TFile("data1.root", "RECREATE");
    auto tree = new TTree("tree", "Tree title");

    Int_t n_turn;
    tree->Branch("n_turn", &n_turn);

    int buffer;
    ifstream ifs(filename);
    while(ifs >> buffer){
        n_turn = buffer;
        tree->Fill();
    }

    tree->Write();
    file_out->Close();

    return 0;
}
