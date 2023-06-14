inline void exam2();

const double m_pion=139.6; //[MeV/c2]
const double m_kaon=493.7; //[MeV/c2}

// timinig resolution [defo: 500 ps]
const double time_resolution = 500e-12;

// momentum resolution [defo: 5 MeV/c]
const double mom_resolution = 5;
const double L = 30.0;// [m]
const double numevents = 1e5;
const double c = 2.99792458 * 1e8; // m/s

const int verbose = 0;
const int sw = 0;

void exam2(){

  gROOT->SetStyle("ATLAS");

  double mom,mom_true, beta, dt, t0, t1;
  
  auto h_pion = new TH2F("h_pion","h_pion",35,1000,4500,35,-1,13);
  auto h_kaon = new TH2F("h_kaon","h_kaon",35,1000,4500,35,-1,13);
    
  for(int j=0;j<numevents;j++){

    mom_true = gRandom->Uniform(1000, 4500);
    mom = gRandom->Gaus(mom_true, mom_resolution);
    if(verbose)
      cout<<"momentum ="<<mom<<" MeV/c; ";
    
    // - pion
    beta = 1./sqrt(1. + pow(m_pion/mom_true,2));
    t0 = L/c;
    t1 = L / beta / c;
    dt = t1 - t0;
    dt = gRandom->Gaus(dt, time_resolution);
    dt *=1e9;
    h_pion->Fill(mom,dt);
    if(verbose)
      cout<<"pion: "<<dt<<" ns; ";
    
    // - kaon
    beta = 1./sqrt(1. + pow(m_kaon/mom,2));
    t1 = L / beta / c;
    dt = t1 - t0;
    dt = gRandom->Gaus(dt, time_resolution);
    dt *=1e9;
    h_kaon->Fill(mom,dt);
    if(verbose)
    cout<<"kaon: "<<dt<<" ns; "<<endl;
  }

  auto c1=new TCanvas("c1");
  h_pion->SetXTitle("p (MeV/c)");
  h_pion->SetYTitle("dt (ns)");
  h_pion->SetLineColor(1);
  h_pion->Draw("box");
  h_kaon->SetLineColor(2);
  h_kaon->Draw("boxsame");

    if(sw<1) return;

    auto hk=new TH1D("hk","hk",35,-1,13);
    auto hp=new TH1D("hp","hp",35,-1,13);
    h_kaon->ProjectionY("hk",10,12);
    h_pion->ProjectionY("hp",10,12);
    hp->Draw();
    hk->Draw("same");
    hp->Fit("gaus","","",-1,5);
    hk->Fit("gaus","","",-1,5);

    if(sw<2) return;

    double sigma = abs(hp->GetFunction("gaus")->GetParameter(1) - hk->GetFunction("gaus")->GetParameter(1))/sqrt(pow(hp->GetFunction("gaus")->GetParameter(2),2)+pow(hk->GetFunction("gaus")->GetParameter(2),2));

    cout<<"significant = "<<sigma<<endl;

  return;
}
