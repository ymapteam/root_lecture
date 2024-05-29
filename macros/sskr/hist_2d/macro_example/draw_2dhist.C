// ----------------------- //
// draw_2dhist.C -- macro
// Author: S. Sakurai
// Date  : May 29 2024
// ----------------------- //

TH2D *make_hist(TString filename = "mock_01")
{
    const int MCACh = 50;
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

int draw_2dhist(TString fname)
{
    TH2D *hist = make_hist(fname);
    hist->SetTitle(";X [a.u.];Y [a.u.]");
    hist->Draw("colz");
    return 0;
}
