//function3.C
void function3(){

  Double_t amp=10;
  Double_t freq=0.5;
  Double_t offset=5;
  
  TF1 *func1 = new TF1("sin","[0]*TMath::Sin(x*[1])+[2]",-4,4);

  func1->SetParameters(amp, freq*2*TMath::Pi(), offset);
  func1->Draw("L");

}

