// plant_tree.C

void plant_tree(){
  // Open file
  TFile *file = new TFile("allsky_photons_300MeV.root", "RECREATE");
  file->cd();

  // Create TTree
  TTree *tree = new TTree("photontree", "Photon tree");

  // Read text file
  tree->ReadFile("../lat-data/allsky_photons_300MeV.dat", "ENERGY/D:L:B:ZENITH_ANGLE:EARTH_AZIMUTH_ANGLE:TIME", ' ');



  
  // Save TTree
  tree->Write();
  file->Close();
}
