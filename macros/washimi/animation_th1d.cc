#include <string>
#include <TROOT.h>
#include <TStyle.h>
#include <TH2.h>
#include <TH1.h>
#include <TCanvas.h>

void animation_th1d(){
  TCanvas *c1 = new TCanvas("c1","c1", 800,600);
  gStyle->SetOptStat(0);
  c1->Draw();
  
  TH1D *h1 = new TH1D("h1","2D Random walk;r;events",101,0,100);
  float x = 0;
  float y = 0;
  float r = 0;
  h1->SetLineWidth(2);
  h1->Draw("e");
  h1->GetYaxis()->SetRangeUser(0,60);
  
  int imax=1000;
  for(int i=0;i<imax+1;i++){
    x +=  gRandom->Gaus();
    y +=  gRandom->Gaus();
    r = pow(x*x+y*y,0.5);
    h1->Fill(r);
    h1->SetTitle(Form("2D Random walk: %i/%i;r;events",i,imax));
    c1->Update();
  }
}









