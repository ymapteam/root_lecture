// ----------------------- //
// draw_hists.C -- macro
// Author: K. Mizukoshi, S.Sakurai
// Date  : May 29 2024
// ----------------------- //

TH1D *make_hist(TString filename = "data1", int axis = 0)
{
    const int MCACh = 50;
    const double HistMin = -10.0;
    const double HistMax = 10.0;

    TH1D *hist = new TH1D(Form("h%d",axis), filename, MCACh, HistMin - 0.5, HistMax - 0.5);

    const TString data_dir = "../data/";
    double BufferValueX;
    double BufferValueY;
    ifstream ifs(data_dir + filename + ".txt");
    while (ifs >> BufferValueX >> BufferValueY)
    {
        if (axis == 0)
        {
            hist->Fill(BufferValueX);
        }
        else if (axis == 1)
        {
            hist->Fill(BufferValueY);
        }
    }
    return hist;
}

int draw_hists()
{
    TH1D *hist1 = make_hist("mock_01", 0);
    TH1D *hist2 = make_hist("mock_01", 1);
    hist1->SetTitle("mock_01;Intensity [a.u.];Counts/Bin");
    hist1->Draw("");
    hist2->SetTitle(";Intensity [a.u.];Counts/Bin");
    hist2->SetLineColor(kBlue);
    hist2->Draw("sames");
    return 0;
}
