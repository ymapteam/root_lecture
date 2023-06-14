void solidangleuniform(double &costheta,
		       double &phi,
		       double &sintheta){
  costheta=gRandom->Uniform(-1.,1.);
  phi=2*TMath::Pi()*gRandom->Uniform(0,1);
  sintheta=sqrt(1.-pow(costheta,2));
  return;
}
