#include "../include/twobodydecay.hh"
void exam4_0(){
  double mK=493.677, mpi=139.6,mpi0=134.1;
  double pK=0, pe=0,pnu=0, pmu=0, ppi=0, ppi0;
  
  twobodydecay(mK, mpi, ppi, mpi0, ppi0);
  cout<<"K->pi+ pi0 decay: p_pi+="<<ppi<<" MeV/c, p_pi0="<<ppi0<<" MeV/c"<<endl;
  return;
}
