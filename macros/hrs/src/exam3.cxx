inline void exam3();

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

void exam3(){

    char particle[100];
    int event, sw;
    double mom,mom_true, beta, dt, t0, t1, m;

    auto file = new TFile("exam3.root","recreate");
    auto tree = new TTree("tree","tree");
    tree->Branch("event",&event,"event/I");
    tree->Branch("particle",&particle,"particle/C");
    tree->Branch("mom",&mom,"mom/D");
    tree->Branch("dt",&dt,"dt/D");

  for(int j=0;j<numevents;j++){
      event  = j;
    sw = (int) gRandom->Uniform(0,2);

    mom_true = gRandom->Uniform(1000, 4500);
    mom = gRandom->Gaus(mom_true, mom_resolution);
    if(verbose)
      cout<<"momentum ="<<mom<<" MeV/c; ";
    
    // - pion
      if(sw==0){
          sprintf(particle,"pi+");
          m=m_pion;
      }
      // - kaon
      else if(sw==1){
          sprintf(particle,"kaon+");
          m=m_kaon;
      }
    beta = 1./sqrt(1. + pow(m/mom_true,2));
    t0 = L/c;
    t1 = L / beta / c;
    dt = t1 - t0;
    dt = gRandom->Gaus(dt, time_resolution);
    dt *=1e9;
    if(verbose)
      cout<<"pion: "<<dt<<" ns; ";

    tree->Fill();
  }

  file->Write();
  return;
}
