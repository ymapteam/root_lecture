#include "../include/twobodydecay.hh"
void exam4_2(){
  double mK=493.677, mpi=139.6,mpi0=134.1, mg1=0., mg2=0.;
  double pK=0, pe=0,pnu=0, pmu=0, ppi=0, ppi0=0, p_pi[3]={0}, p_pi0[3]={0};
  double Epi, Eg1, pg1, Eg2, pg2, p_g1[3]={0}, p_g2[3]={0};
  double beta, gamma;
  double costheta, sintheta, phi;

  gRandom->SetSeed(2);
  
  // kaon decay to 2 pions at kaon rest system
  twobodydecay(mK, mpi, ppi, mpi0, ppi0);
  Epi=sqrt(pow(mpi0,2) + pow(ppi0,2));
  
  // -- set pi0 momentum
  p_pi0[0]=0;
  p_pi0[1]=0;
  p_pi0[2]=ppi; // <= assumption p_z = 205.4 MeV/c;

  beta = ppi / Epi;
  gamma=1./sqrt(1.-pow(beta,2));
 
  // pi0 decay to 2 gammas at pi0 rest system
  twobodydecay(mpi0, mg1, pg1, mg2, pg2);
  Eg1 = sqrt(pg1*pg1);
  Eg2 = sqrt(pg2*pg2);

  // randomize emission direction
  costheta=gRandom->Uniform(-1.,1.);
  phi=2*TMath::Pi()*gRandom->Uniform(0,1);  
  sintheta=sqrt(1.-pow(costheta,2));
  
  p_g1[0]=pg1*sintheta*cos(phi);
  p_g1[1]=pg1*sintheta*sin(phi);
  p_g1[2]=pg1*costheta;

  p_g2[0]=-pg2*sintheta*cos(phi);
  p_g2[1]=-pg2*sintheta*sin(phi);
  p_g2[2]=-pg2*costheta;

  // Lorentz boost
  p_g1[2] = gamma*beta*Eg1 + gamma*p_g1[2];
  p_g2[2] = gamma*beta*Eg2 + gamma*p_g2[2];
  
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
      <<"\t momentum vec = ("<<p_g1[0]<<", "<<p_g1[1]<<", "<<p_g1[2]<<") NeV/c"<<endl;

  cout<<"gamma 2:"<<endl
      <<"\t Energy = "<<Eg2<<" MeV"<<endl
      <<"\t momentum vec = ("<<p_g2[0]<<", "<<p_g2[1]<<", "<<p_g2[2]<<") NeV/c"<<endl;

  return;
}
