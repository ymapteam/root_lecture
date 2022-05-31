// friend_tree.C

void friend_tree(){
  // Target object: 3C 279
  const Double_t L_obj = 305.104320 * TMath::DegToRad(); // Galactic latitude
  const Double_t B_obj = 57.062406 * TMath::DegToRad(); // Galactic longitude

  // Make 3D-vector toward 3C 279
  const Double_t X_obj = TMath::Cos(L_obj) * TMath::Cos(B_obj);
  const Double_t Y_obj = TMath::Sin(L_obj) * TMath::Cos(B_obj);
  const Double_t Z_obj = TMath::Sin(B_obj);
  cout << "3C 279" << endl;
  cout << "(X, Y, Z)=" << X_obj << "," << Y_obj << "," << Z_obj << endl;
  
  // Open input file
  TFile *file = new TFile("allsky_photons_300MeV.root", "UPDATE");
  TTree *tree = (TTree*)file->Get("photontree");

  Double_t l_deg, b_deg;
  tree->SetBranchAddress("L", &l_deg);
  tree->SetBranchAddress("B", &b_deg);

  // Open output file
  TFile *file_out = new TFile("allsky_photons_300MeV_3C279.root", "RECREATE");
  TTree * friendtree = new TTree("friendtree", "Friend tree");
  Double_t angle_deg;
  friendtree->Branch("ANGLE_3C279", &angle_deg, "ANGLE_3C279/D");
  

  Double_t l_ph, b_ph;
  Double_t x_ph, y_ph, z_ph;
  Double_t dotprod, angle_rad;
  
  for(Int_t i=0; i<tree->GetEntries(); i++){
    tree->GetEntry(i);
    
    l_ph = l_deg * TMath::DegToRad();
    b_ph = b_deg * TMath::DegToRad();

    // Make 3D-vector toward gamma-ray arrival direction
    x_ph = TMath::Cos(l_ph) * TMath::Cos(b_ph);
    y_ph = TMath::Sin(l_ph) * TMath::Cos(b_ph);
    z_ph = TMath::Sin(b_ph);

    // Calculate dot-product
    dotprod  = X_obj*x_ph + Y_obj*y_ph + Z_obj*z_ph;
    
    // Convert dot-product to angle
    if(dotprod>=1)
      angle_rad = 0;
    else if(dotprod<=-1)
      angle_rad = -TMath::Pi();
    else
      angle_rad = TMath::ACos(dotprod);
    
    angle_deg = angle_rad * TMath::RadToDeg();
    friendtree->Fill();
  }

  // Save TTree
  file_out->cd();
  friendtree->Write();

  // Add new tree to main tree as friend
  tree->AddFriend(friendtree->GetName(), file_out);
  
  file->cd();
  tree->Write();
  file->Close();
  file_out->Close();
}
