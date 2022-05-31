// project_hist2D.C

void project_hist2D(){
  gROOT->SetStyle("ATLAS");
  
  // X-axis
  const Int_t total_xbin = 20;
  const Int_t min_xbin = 0;
  const Int_t max_xbin = 10;
  // Y-axis
  const Int_t total_ybin = 20;
  const Int_t min_ybin = -10;
  const Int_t max_ybin = 10;

  TH2D * hist2D = new TH2D("hist2D", "2D Histogram",
			   total_xbin, min_xbin, max_xbin,
			   total_ybin, min_ybin, max_ybin);

  // Diffusion function
  TF1* func_diffuse = new TF1("func_diffuse",
			      "TMath::Exp(-(x+[2]*TMath::Sin([1]/[3]))*(x+[2]*TMath::Sin([1]/[3]))/(4.*[0]*[1]))/(2.*TMath::Sqrt(TMath::Pi()*[0]*[1]))",
			      min_ybin, max_ybin);
  func_diffuse->SetParameter(0,3); // Diffusion coefficient
  func_diffuse->SetParameter(2, 4);
  func_diffuse->SetParameter(3, 1);
  
  Double_t val;
  Double_t t=0.001;
  while(t<max_xbin){
    func_diffuse->SetParameter(1,t);
    val = func_diffuse->GetRandom(min_ybin, max_ybin);
    //cout << t << ": " << val << endl;
    hist2D->Fill(t, val);
    t += 0.001;
  }

  hist2D->Draw();

  TCanvas *can = new TCanvas("canvas", "canvas");
  can->Divide(2,2);

  can->cd(1);
  hist2D->Draw("COLZ");
  can->cd(2);
  TH1D* hist_projectionY = hist2D->ProjectionY("hist_projY");
  hist_projectionY->SetTitle("Projection onto Y-axis");
  hist_projectionY->Draw();
  can->cd(3);
  TH1D* hist_projectionX = hist2D->ProjectionX("hist_projX", 1, 10);
  hist_projectionX->SetTitle("Projection onto X-axis");
  hist_projectionX->Draw();
}
