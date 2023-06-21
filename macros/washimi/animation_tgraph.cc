#include <string>
#include <TROOT.h>
#include <TStyle.h>
#include <TH2.h>
#include <TGraph.h>
#include <TCanvas.h>

void animation_tgraph(){
  TCanvas *c1 = new TCanvas("c1","c1", 600,600);
  TH2D    *h2 = new TH2D("h2","2D Random walk;x;y",101,-100,100,101,-100,100);
  gStyle->SetOptStat(0);
  c1->Draw();
  h2->SetLineWidth(0);
  h2->Draw();
  //gSystem->Unlink("animation_tgraph.gif");
  
  TGraph  *g1 = new TGraph();
  float x = 0;
  float y = 0;
  g1->SetPoint(1,x,y);  
  g1->Draw("pl");
  
  int imax=1000;
  for(int i=0;i<imax+1;i++){
    x +=  gRandom->Gaus();
    y +=  gRandom->Gaus();
    g1->SetPoint(i+2,x,y);
    h2->SetTitle(Form("2D Random walk: %i/%i;x;y",i,imax));
    c1->Update();
    //c1->Print("animation_tgraph.gif+");
  }
}









