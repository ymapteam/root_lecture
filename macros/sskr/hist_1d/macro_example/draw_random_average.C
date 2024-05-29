// ----------------------- //
// draw_random_average.C -- macro
// Author: S. Sakurai
// Date  : May 29 2024
// ----------------------- //

TF1 *define_dist();

void draw_random_average()
{
    TCanvas *c1 = new TCanvas("c1", "c1", 800, 800);
    TF1 *f1 = define_dist();
    const double max_bin_edge = 100;
    const double min_bin_edge = 0;
    const int n_bin = 1000;
    const int n_sample = 1000;
    const int n_test = 5;
    int n_sums[n_test];
    double sums[n_test];
    TH1D *hists[n_test];
    for (int i = 0; i < n_test; i++)
    {
        // No specific reason of these numbers.
        n_sums[i] = 10 * TMath::Power(4, i);
        sums[i] = 0;
        // The number of bins is not unique!! Due to central limit theorem!!
        hists[i] = new TH1D(Form("h%d", i), Form("h%d", i), (int)((double)n_bin / TMath::Power(2, n_test - (i + 1))), min_bin_edge, max_bin_edge);
    }

    for (int i = 0; i < n_sample; i++)
    {
        for (int j = 0; j < n_test; j++)
        {
            for (int k = 0; k < n_sums[j]; k++)
            {
                sums[j] += f1->GetRandom();
            }
            hists[j]->Fill(sums[j] / n_sums[j]);
            sums[j] = 0;
        }
    }
    hists[0]->SetTitle("Central Limit Theorem;X [a.u.];Entries / Maximum");
    hists[0]->Draw("hist");
    for (int j = 0; j < n_test; j++)
    {
        hists[j]->Scale(1 / hists[j]->GetMaximum());
        hists[j]->SetLineColor(kRed + j);
        if (j > 0)
        {
            hists[j]->Draw("sames hist");
        }
    }
}

TF1 *define_dist()
{
    // You have not learned yet.
    TF1 *f = new TF1("f1", "gaus(0)+gaus(3)+gaus(6)", 0, 100);
    const double height_A = 12.0;
    const double height_B = 6.0;
    const double height_C = 4.0;
    const double mu_A = 30.0;
    const double mu_B = 60.0;
    const double mu_C = 50.0;
    const double sigma_A = 2.0;
    const double sigma_B = 1.0;
    const double sigma_C = 10.0;
    f->SetParameters(height_A, mu_A, sigma_A, height_B, mu_B, sigma_B, height_C, mu_C, sigma_C);
    return f;
}