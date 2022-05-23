//function2.C
void function2(){

  TF1 *func1 = new TF1("niji","40*x*x-20",-1,1);
  TF1 *func2 = new TF1("sanji","TMath::Power(5*x,3)",-1,1);
  TF1 *func3 = new TF1("sin","5*TMath::Sin(5*x)-5",-1,1);
  TF1 *func4 = new TF1("exp","TMath::Exp(5*x)",-1,1);
  TF1 *func5 = new TF1("log","8*TMath::Log(1-x)+2*TMath::Log(x)",0,1);
  TF1 *func6 = new TF1("gaus","15*TMath::Gaus(x,-0.5,0.1)",-1,1);

  func2->SetLineColor(4);//ao
  func3->SetLineColor(3);//midori
  func4->SetLineColor(5);//ki
  func5->SetLineColor(6);//momo
  func6->SetLineColor(7);//mizu

  func1->Draw();
  func2->Draw("same");
  func3->Draw("same");
  func4->Draw("same");
  func5->Draw("same");
  func6->Draw("same");

}


