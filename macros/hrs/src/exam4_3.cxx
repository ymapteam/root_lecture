#include "../include/twobodydecay.hh"
#include "../include/solidangleuniform.hh"
#include "../include/lorentz.hh"
void exam4_3(){
  double mK=493.677, mpi=139.6,mpi0=134.1, mg1=0., mg2=0.;
  double pK=0, pe=0,pnu=0, pmu=0, ppi=0, ppi0=0, p_pi[3]={0}, p_pi0[3]={0};
  double Epi, Eg1, pg1, Eg2, pg2, p_g1[3]={0}, p_g2[3]={0};
  double beta[3];
  double costheta1, sintheta1, phi1;
  double costheta2, sintheta2, phi2;
  double total_mom[3]={0};

  for(int event = 0; event < 10; event++){

    cout<<"=================="<<endl;
    cout<<"Event "<<event<<endl;
    
    // kaon decay to 2 pions at kaon rest system
    twobodydecay(mK, mpi, ppi, mpi0, ppi0);
    solidangleuniform(costheta1,phi1,sintheta1);
    
    p_pi[0]=ppi*sintheta1*cos(phi1);
    p_pi[1]=ppi*sintheta1*sin(phi1);
    p_pi[2]=ppi*costheta1;

    Epi=sqrt(pow(mpi,2)+pow(p_pi[0],2)+pow(p_pi[1],2)+pow(p_pi[2],2));
    cout<<"pi+:"<<endl
	<<"\t Energy = "<<Epi<<" MeV"<<endl
	<<"\t Momentum = "<<ppi<<" MeV/c"<<endl
	<<"\t Momentum vec = ("<<p_pi[0]<<", "<<p_pi[1]<<", "<<p_pi[2]<<") NeV/c"<<endl;
    
    p_pi0[0]=-ppi0*sintheta1*cos(phi1);
    p_pi0[1]=-ppi0*sintheta1*sin(phi1);
    p_pi0[2]=-ppi0*costheta1;

    //beta = ppi / Epi;
    for(int i=0;i<3;i++)
      beta[i] = p_pi[i] / Epi;
    
    // pi0 decay to 2 gammas at pi0 rest system
    twobodydecay(mpi0, mg1, pg1, mg2, pg2);
    solidangleuniform(costheta2,phi2,sintheta2);
    
    Eg1 = sqrt(pg1*pg1);
    Eg2 = sqrt(pg2*pg2);
    
      p_g1[0]=pg1*sintheta2*cos(phi2);
      p_g1[1]=pg1*sintheta2*sin(phi2);
      p_g1[2]=pg1*costheta2;

      p_g2[0]=-pg2*sintheta2*cos(phi2);
      p_g2[1]=-pg2*sintheta2*sin(phi2);
      p_g2[2]=-pg2*costheta2;

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
	<<"\t Momentum = vec ("<<p_g1[0]<<", "<<p_g1[1]<<", "<<p_g1[2]<<") MeV/c"<<endl;
    
    cout<<"gamma 2:"<<endl
	<<"\t Energy = "<<Eg2<<" MeV"<<endl
	<<"\t Momentum = "<<pg2<<" MeV"<<endl
	<<"\t Momentum = vec ("<<p_g2[0]<<", "<<p_g2[1]<<", "<<p_g2[2]<<") MeV/c"<<endl;
    
  }
  
  return;
}
