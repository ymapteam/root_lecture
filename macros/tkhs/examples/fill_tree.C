// fill_tree.C

void fill_tree(){
  // Open output file
  TFile *file = new TFile("allsky_photons_1GeV.root", "RECREATE");
  file->cd();

  // Create TTree
  TTree *tree = new TTree("photontree", "Photon tree");
  
  Float_t energy, l, b, zenith, azimuth;
  Double_t time;
  tree->Branch("ENERGY", &energy, "ENERGY/F");
  tree->Branch("L", &l, "L/F");
  tree->Branch("B", &b, "B/F");
  tree->Branch("ZENITH_ANGLE", &zenith, "ZENITH_ANGLE/F");
  tree->Branch("EARTH_AZIMUTH_ANGLE", &azimuth, "EARTH_AZIMUTH_ANGLE/F");
  tree->Branch("TIME", &time, "TIME/D");

  // Open input file
  ifstream ifs("../lat-data/allsky_photons_300MeV.dat");
  // Check if input file is open
  if(!ifs.is_open()){
    cout << "Input file is not opened!" << endl;
    return 0;
  }

  while(ifs >> energy >> l >> b >> zenith >> azimuth >> time){
    if(energy>=1000){ // ENERGY>=1 GeV
      l = l>180 ? l-360.:l; // Modify Galactic longitude to center Origin (Galactic Center)
      /* Same as
	 if(l>180.)
	 l = l-360.;
      */
      tree->Fill();
    }
  }

  // Save TTree
  tree->Write();
  file->Close();
}
