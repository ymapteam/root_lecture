// --------------------------- //
// rdataframe.C
// Tree reading example
// Author : Keita Mizukoshi
// 2024 Jun. 11
// --------------------------- //


int rdataframe(TString filename="../data/gamma_1_5MeV_10000_0.root"){

    ROOT::RDataFrame df("tree", filename);

    auto hist = df.Filter("nHit>0").Histo1D("total_adc");
    hist->Draw();
    hist->Draw();

    return 0;
}
