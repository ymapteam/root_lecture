// --------------------------- //
// tchain.C
// Multi tree reading example
// Author : Keita Mizukoshi
// 2024 Jun. 11
// --------------------------- //


int tchain(){
    auto tree = new TChain("tree", "title");
    tree->Add("../data/gamma_1_5MeV_10000_0.root");
    tree->Add("../data/gamma_1_5MeV_10000_1.root");
    tree->Add("../data/gamma_1_5MeV_10000_2.root");
    tree->Add("../data/gamma_1_5MeV_10000_3.root");
    tree->Add("../data/gamma_1_5MeV_10000_4.root");
    // tree->Add("../data/gamma_1_5MeV_10000_*.root");
    
    cout << tree->GetEntries() << endl;

    return 0;
}
