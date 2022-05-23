// draw_graph2.C

void draw_graph2(){

  double ene[4] = {662, 1274, 511, 662};
  double mean[4] = {2956.57, 5673.64, 2300.42, 1556.57};
  double sigma[4] = {158.93, 221.79, 172.97, 155.98};

  TGraph *g_CsI_mean = new TGraph();
  for(int i=0; i<3; i++) g_CsI_mean->SetPoint(i, ene[i], mean[i]);

  TGraph *g_CsI_resolution = new TGraph();
  for(int i=0; i<3; i++) g_CsI_resolution->SetPoint(i, ene[i], sigma[i]/mean[i]*100*2.35);

  TGraph *g_GAGG_mean = new TGraph();
  g_GAGG_mean->SetPoint(0, ene[3], mean[3]);

  TGraph *g_GAGG_resolution = new TGraph();
  g_GAGG_resolution->SetPoint(0, ene[3], sigma[3]/mean[3]*100*2.35);

  g_CsI_mean->SetMarkerStyle(2);
  g_CsI_mean->SetMarkerColor(2);
  g_CsI_resolution->SetMarkerStyle(2);
  g_CsI_resolution->SetMarkerColor(2);
  g_GAGG_mean->SetMarkerStyle(4);
  g_GAGG_mean->SetMarkerColor(4);
  g_GAGG_resolution->SetMarkerStyle(4);
  g_GAGG_resolution->SetMarkerColor(4);

  TCanvas *c = new TCanvas("c","c",1200,500);
  c->Divide(2,1);
  for(int i=0; i<2; i++) c->cd(1)->SetMargin(0.15,0.1,0.1,0.1);
  
  c->cd(1)->DrawFrame(0,0,1500,6000,"linearity; energy [keV]; mean [ADC]");
  g_CsI_mean->Draw("sameP");
  g_GAGG_mean->Draw("sameP");

  c->cd(2)->DrawFrame(0,0,1500,30,"resolution; energy [keV]; FWHM [%]");
  g_CsI_resolution->Draw("sameP");
  g_GAGG_resolution->Draw("sameP");
  
}

