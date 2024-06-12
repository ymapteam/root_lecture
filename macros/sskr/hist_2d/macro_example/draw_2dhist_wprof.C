// ----------------------- //
// draw_2dhist_wprof.C -- macro
// Author: S. Sakurai
// Date  : May 29 2024
// ----------------------- //

TH2D *make_hist(TString filename = "mock_01")
{
    const int MCACh = 20;
    const double HistMin = -10.0;
    const double HistMax = 10.0;

    TH2D *hist = new TH2D(filename, filename,
                          MCACh, HistMin - 0.5, HistMax - 0.5, //0.5 is an offset to cet 0 to a bin center.
                          MCACh, HistMin - 0.5, HistMax - 0.5);

    const TString data_dir = "../data/";
    double BufferValueX;
    double BufferValueY;
    std::ifstream ifs(data_dir + filename + ".txt");
    while (ifs >> BufferValueX >> BufferValueY)
    {
        hist->Fill(BufferValueX, BufferValueY);
    }
    return hist;
}

int draw_2dhist_wprof(TString fname)
{
    TH2D *hist = make_hist(fname);
    TProfile *prof = (TProfile *)hist->ProfileX();
    hist->SetTitle(";X [a.u.];Y [a.u.]");
    hist->Draw("cont1z");
    prof->SetLineColor(kRed);
    prof->Draw("same");
    return 0;
}
