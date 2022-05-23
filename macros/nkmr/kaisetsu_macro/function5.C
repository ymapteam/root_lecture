//function5.C
// WARNING: v_E, v_esc, etc are not considered !
//          Do not believe the result
//          "J.D.Lewin and P.F.Smith, Astroparticle Physics 6 (1996) 87-112"

Double_t dRdE(double E_R, double mass_DM, double A){
  double v_0 = 230;
  double rho_DM = 0.4;
  double sigma_0 = 1.0;
  double mass_p = 0.932;
  double R_0 = 2.0/TMath::Sqrt(TMath::Pi()) * 6.02e26/A *rho_DM/mass_DM *sigma_0*1e-36 *v_0*1e5 *60*60*24;
  double v_c=3.0e5; // km/s
  double E_0 = 0.5*mass_DM*v_0*v_0/v_c/v_c *1000000;
  double r = 4.0*mass_DM*A*mass_p/TMath::Power(mass_DM+A*mass_p, 2);
  return R_0/E_0/r*TMath::Exp(-E_R/E_0/r);
}

Double_t cross_section_ratio_for_proton(double mass_DM, double A, int mode, double Ja=0.75){
  double mass_p = 0.932;
  if(     mode==0) return A*A*TMath::Power(A*(mass_DM+mass_p)/(mass_DM+mass_p*A), 2);//SI
  else if(mode==1) return Ja/0.75*TMath::Power(A*(mass_DM+mass_p)/(mass_DM+mass_p*A), 2);//SD
  else             return -1;
}

Double_t form_factor(double E_R, double A, int mode){
  double s=0.9;
  double      r_n=1.14*TMath::Power(A,1.0/3.0);//SI
  if(mode==1) r_n=1.0 *TMath::Power(A,1.0/3.0);//SD
  double q=6.92*0.001*TMath::Sqrt(A*E_R);
  double qr=q*r_n;
  if(     mode==0) return TMath::Power(3*(sin(qr)-qr*cos(qr))/qr/qr/qr, 2) *TMath::Exp(-q*q*s*s/2.0);//SI
  else if(mode==1) return TMath::Power(sin(qr)/qr, 2) *TMath::Exp(-q*q*s*s/2.0);//SD
  else             return -1;
}


void function5(){

  // parameters
  Double_t mass_DM = 100;//GeV/c^2
  Double_t A_array[3] = {19, 73, 131};// 19F, 73Ge, 131Xe
  Double_t Ja_array[3] = { 0.647*1.0, 0.065*0.078, 0.055*0.212 };// J-factor times abundance
  int mode = 0;// SI:0, SD:1
  
  // canvas
  int i_color[3] = {2,3,4};
  TCanvas *c = new TCanvas("c","c",1000,1000);
  c->Divide(2,2);

  c->cd(1)->SetMargin(0.15,0.1,0.1,0.1);
  c->cd(1)->DrawFrame(0,0,400,0.02,"energy spectrum (raw);recoil energy [keV];event rate [count/keV/kg/days]");
  TF1 *func1[3];
  for(int i=0; i<3; i++){
    func1[i]= new TF1(Form("f1_%d",i),"dRdE(x,[0],[1])",0,400);
    func1[i]->SetParameters(mass_DM, A_array[i]);
    func1[i]->SetLineColor(i_color[i]);
    func1[i]->Draw("same");
  }

  if(mode==0) c->cd(2)->DrawFrame(0,1e3,100,1e8,"cross section ratio (SI);DM mass [GeV];ratio for proton");
  if(mode==1) c->cd(2)->DrawFrame(0,1e-2,100,1e3,"cross section ratio (SD);DM mass [GeV];ratio for proton");
  c->cd(2)->SetLogy(1);
  TF1 *func2[3];
  for(int i=0; i<3; i++){
    func2[i] = new TF1(Form("f2_%d",i),"cross_section_ratio_for_proton(x,[0],[1],[2])",0,100);
    func2[i]->SetParameters(A_array[i], mode, Ja_array[i]);
    func2[i]->SetLineColor(i_color[i]);
    func2[i]->Draw("same");
  }

  if(mode==0) c->cd(3)->DrawFrame(0,1e-5,400,1,"nuclear form factor (SI);recoil energy [keV];ratio");
  if(mode==1) c->cd(3)->DrawFrame(0,1e-5,400,1,"nuclear form factor (SD);recoil energy [keV];ratio");
  c->cd(3)->SetLogy(1);
  TF1 *func3[3];
  for(int i=0; i<3; i++){
    func3[i] = new TF1(Form("f3_%d",i),"form_factor(x,[0],[1])",0,1000);
    func3[i]->SetParameters(A_array[i], mode);
    func3[i]->SetLineColor(i_color[i]);
    func3[i]->Draw("same");
  }

  if(mode==0) c->cd(4)->DrawFrame(0,1e0,400,1e5,"energy spectrum (SI);recoil energy [keV];event rate [count/keV/kg/days]");
  if(mode==1) c->cd(4)->DrawFrame(0,1e-4,400,1e1,"energy spectrum (SD);recoil energy [keV];event rate [count/keV/kg/days]");
  c->cd(4)->SetLogy(1);
  TF1 *func4[3];
  for(int i=0; i<3; i++){
    func4[i] = new TF1(Form("f4_%d",i),"dRdE(x,[0],[1])*cross_section_ratio_for_proton([0],[1],[2],[3])*form_factor(x,[1],[2])",0,1000);
    func4[i]->SetParameters(mass_DM, A_array[i], mode, Ja_array[i]);
    func4[i]->SetLineColor(i_color[i]);
    func4[i]->Draw("same");
  }

  // legend
  TLegend *leg = new TLegend(0.5,0.5,0.8,0.8);
  leg->AddEntry(func1[0],"^{19}F","l");  
  leg->AddEntry(func1[1],"^{73}Ge","l");  
  leg->AddEntry(func1[2],"^{131}Xe","l");  
  leg->Draw();
}

