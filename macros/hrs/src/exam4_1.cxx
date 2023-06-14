#include "../include/twobodydecay.hh"
void exam4_1(){
  double mK=493.677, mpi=139.6,mpi0=134.1;
  double pK=0, pe=0,pnu=0, pmu=0, ppi=0, ppi0=0, p_pi[3]={0}, p_pi0[3]={0};
  double Epi, Eg1, pg1, Eg2, pg2, p_g1[3]={0}, p_g2[3]={0};
  double beta, gamma;
  
    // kaon decay to 2 pions at kaon rest system
    twobodydecay(mK, mpi, ppi, mpi0, ppi0);
    Epi=sqrt(pow(mpi0,2) + pow(ppi0,2));

    // -- set pi0 momentum
    p_pi0[0]=0;
    p_pi0[1]=0;
    p_pi0[2]=ppi; // <= assumption p_z = 205.4 MeV/c;

    beta = ppi / Epi;
    gamma=1./sqrt(1.-pow(beta,2));
    cout<<"beta = "<<beta<<endl;
    cout<<"gamma = "<<gamma<<endl;
  
  return;
}
