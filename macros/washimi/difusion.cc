#include <string>
#include <TROOT.h>
#include <TStyle.h>
#include <TH1.h>
#include <TH2.h>
#include <TGraph.h>
#include <TCanvas.h>

void difusion(){
  TCanvas *c1 = new TCanvas("c1","c1", 1200,600);

  c1->Divide(2,1);
  c1->cd(2);
  TH1D *h1 = new TH1D("h1","2D Difusion;r;events",101,0,100);
  h1->Draw("e");
  h1->GetYaxis()->SetRangeUser(0,100);
  
  c1->cd(1);
  TH2D    *h2 = new TH2D("h2","2D Difusion;x;y",101,-100,100,101,-100,100);
  gStyle->SetOptStat(0);
  c1->Draw();
  h2->SetLineWidth(0);
  h2->Draw();
  
  TGraph  *g1 = new TGraph();
  const int N = 1000;
  float x[N] = {0};
  float y[N] = {0};
  float r = 0;
  
  int imax=1000;
  for(int i=0;i<imax+1;i++){
    h1->Reset();
    for(int j=0;j<N;j++){
      x[j] +=  gRandom->Gaus();
      y[j] +=  gRandom->Gaus();
      r = pow(x[j]*x[j] + y[j]*y[j],0.5);
      h1->Fill(r);  
    }
    
    delete g1;
    TGraph *g1 = new TGraph(N,x,y);
    c1->cd(1);
    g1->SetMarkerStyle(8);
    g1->Draw("p");    
    h2->SetTitle(Form("2D difusion: %i/%i;x;y",i,imax));
    
    c1->cd(2);
    h1->Draw("e");
    
    c1->Update();    
  }
}









