inline void exam1();
const double m_electron=0.511; // MeV/c2
const double m_muon=105.6;     // MeV/c2
const double m_pion=139.6;     // MeV/c2
const double m_kaon=493.7;     // MeV/c2
const double m_proton=938.3;   // MeV/c2
const int n = 5;

void exam1(){
    gROOT->SetStyle("ATLAS");
  
  double mom, beta;
  double m[n]={
    m_electron, m_muon, m_pion,
    m_kaon, m_proton
  };

  auto c1=new TCanvas("c1");  

  TGraph* graph[n];
  for(int j=0;j<n;j++){
    graph[j] = new TGraph();
    for(int i=0;i<100;i++){
      mom = i*20+10;//MeV/c
      beta = 1./sqrt(1. + pow(m[j]/mom,2));
      graph[j]->SetPoint(i, mom, beta);
    }
    graph[j]->SetLineColor(j+2);
    graph[j]->SetLineWidth(3);
    if(j==0){
      graph[0]->GetHistogram()->SetMinimum(0);
      graph[0]->GetHistogram()->SetMaximum(1);
      graph[0]->GetXaxis()->SetLimits(0,2000);
      graph[0]->GetXaxis()->SetTitle("Momentum (MeV/c)");
      graph[0]->GetYaxis()->SetTitle("Ratio of velocity to c");
      graph[0]->Draw("al");
    }
    else graph[j]->Draw("l"); 
  }

  return;
}
