//function4.C

Double_t dRdE(double E_R, double mass_DM, double A){
  double v_0 = 230;
  double rho_DM = 0.4;
  double sigma_0 = 1.0;
  double mass_p = 0.932;
  double R_0 = 2.0/TMath::Sqrt(TMath::Pi()) * 6.02e26/A *rho_DM/mass_DM *sigma_0*1e-36 *v_0*1e5 *60*60*24;
  double v_c=3.0e5; // km/s
  double E_0 = 0.5*mass_DM*v_0*v_0/v_c/v_c *1000000; // GeV-->keV
  double r = 4.0*mass_DM*A*mass_p/TMath::Power(mass_DM+A*mass_p, 2);
  return R_0/E_0/r*TMath::Exp(-E_R/E_0/r);
}

void function4(){
  
  TF1 *func1 = new TF1("energy spectrum","dRdE(x,[0],[1])",0,400);
  func1->SetParameters(100, 131);
  func1->Draw();
  
}

