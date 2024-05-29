// ----------------------- //
// draw_random_minimum.C -- macro
// Author: S. Sakurai
// Date  : May 29 2024
// ----------------------- //

TF1 *define_dist();

void draw_random_minimum()
{
    // You have not learned yet.
    TF1 *f1 = define_dist();
    // You can get a random number following a certain distribution.
    f1->GetRandom();
    // You can also draw a function.
    f1->Draw();
}

TF1 *define_dist()
{
    // You have not learned yet.
    TF1 * f = new TF1("f1", "gaus(0)+gaus(3)+gaus(6)", 0, 100);
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