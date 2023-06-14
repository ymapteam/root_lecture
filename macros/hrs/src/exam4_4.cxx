#include "../include/twobodydecay.hh"
#include "../include/solidangleuniform.hh"
#include "../include/lorentz.hh"

const int total_number = 10000;
void exam4_4(){
  double mK=493.677, mpi=139.6,mpi0=134.1, mg1=0., mg2=0.;
  double pK=0, pe=0,pnu=0, pmu=0, ppi=0, ppi0=0, p_pi[3]={0}, p_pi0[3]={0};
  double Epi=0, Eg1, pg1, Eg2, pg2, p_g1[3]={0}, p_g2[3]={0};
  double beta[3]={0}, gamma[3]={0};
  double costheta, sintheta, phi;
  int event=0;
  
  auto file=new TFile("exam4.root","recreate");
  auto tree=new TTree("tree","tree");
  tree->Branch("event",&event,"event/I");
  tree->Branch("Epi",&Epi,"Epi/D");
  tree->Branch("ppi",&ppi,"ppi/D");
  tree->Branch("p_pi[3]",p_pi,"p_pi[3]/D");
  tree->Branch("Eg1",&Eg1,"Eg1/D");
  tree->Branch("pg1",&pg1,"pg1/D");
  tree->Branch("p_g1[3]",p_g1,"p_g1[3]/D");
  tree->Branch("Eg2",&Eg2,"Eg2/D");
  tree->Branch("pg2",&pg2,"pg2/D");
  tree->Branch("p_g2[3]",p_g2,"p_g2[3]/D");
  
  for(event = 0; event < total_number; event++){

    cout<<"=================="<<endl;
    cout<<"Event "<<event<<endl;
    
    // kaon decay to 2 pions at kaon rest system
    twobodydecay(mK, mpi, ppi, mpi0, ppi0);
    solidangleuniform(costheta,phi,sintheta);
    
    p_pi[0]=ppi*sintheta*cos(phi);
    p_pi[1]=ppi*sintheta*sin(phi);
    p_pi[2]=ppi*costheta;

    Epi=sqrt(pow(mpi,2)+pow(p_pi[0],2)+pow(p_pi[1],2)+pow(p_pi[2],2));
    cout<<"pi+:"<<endl
	<<"\t Energy = "<<Epi<<" MeV"<<endl
	<<"\t Momentum = "<<ppi<<" MeV/c"<<endl
	<<"\t Momentum vec = ("<<p_pi[0]<<", "<<p_pi[1]<<", "<<p_pi[2]<<") NeV/c"<<endl;
   
    p_pi0[0]=-ppi0*sintheta*cos(phi);
    p_pi0[1]=-ppi0*sintheta*sin(phi);
    p_pi0[2]=-ppi0*costheta;

    //beta = ppi / Epi;
    for(int i=0;i<3;i++)
      beta[i] = p_pi[i] / Epi;
    
    
    // pi0 decay to 2 gammas at pi0 rest system
    twobodydecay(mpi0, mg1, pg1, mg2, pg2);
    solidangleuniform(costheta,phi,sintheta);
      
    Eg1 = sqrt(pg1*pg1);
    Eg2 = sqrt(pg2*pg2);
    
      p_g1[0]=pg1*sintheta*cos(phi);
      p_g1[1]=pg1*sintheta*sin(phi);
      p_g1[2]=pg1*costheta;

      p_g2[0]=-pg2*sintheta*cos(phi);
      p_g2[1]=-pg2*sintheta*sin(phi);
      p_g2[2]=-pg2*costheta;
    
    // Lorentz boost 
    //for(int j=0;j<3;j++){
    //  p_g1[j] = gamma[j]*beta[j]*Eg1 + gamma[j]*p_g1[j];
    //  p_g2[j] = gamma[j]*beta[j]*Eg2 + gamma[j]*p_g2[j];
    //}

    // Lorentz boost
    lorentz(Eg1, p_g1[0],p_g1[1],p_g1[2], beta[0],beta[1],beta[2]);
    lorentz(Eg2, p_g2[0],p_g2[1],p_g2[2], beta[0],beta[1],beta[2]);
    
    Eg1 = 0;
    for(int j=0;j<3;j++) Eg1+=pow(p_g1[j],2);
    Eg1=sqrt(Eg1);
    pg1=Eg1;
    Eg2 = 0;
    for(int j=0;j<3;j++) Eg2+=pow(p_g2[j],2);
    Eg2=sqrt(Eg2);
    pg2=Eg2;
    
    cout<<"gamma 1:"<<endl
	<<"\t Energy = "<<Eg1<<" MeV"<<endl
	<<"\t Momentum = "<<pg1<<" MeV"<<endl
	<<"\t Momentum = vec ("<<p_g1[0]<<", "<<p_g1[1]<<", "<<p_g1[2]<<") NeV/c"<<endl;
    
    cout<<"gamma 2:"<<endl
	<<"\t Energy = "<<Eg2<<" MeV"<<endl
	<<"\t Momentum = "<<pg2<<" MeV"<<endl
	<<"\t Momentum = vec ("<<p_g2[0]<<", "<<p_g2[1]<<", "<<p_g2[2]<<") NeV/c"<<endl;

    tree->Fill();
  }

  file->Write();
  return;
}
