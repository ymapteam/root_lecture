void lorentz(double &Ene,
	     double &mom1, double &mom2, double &mom3,
	     double beta1, double beta2, double beta3){

  double mom[3] = {mom1, mom2, mom3};
  double beta[3] = {beta1,beta2,beta3};
  double mass = sqrt(Ene*Ene - mom[0]*mom[0] - mom[1]*mom[1] - mom[2]*mom[2]);

  // -- calc absolute beta from beta vector 
  double absbeta = 0;
  for(int i=0;i<3;i++)
    absbeta += pow(beta[i],2);
  absbeta = sqrt(absbeta);
  if(absbeta==0) return;
  // -- calc gamma from beta 
  double gamma = 1. / sqrt(1. - absbeta*absbeta);

  // -- boost vector (solid angle) caluclate
  double costheta, sintheta, cosphi, sinphi, phi, theta;
  costheta = beta[2] / absbeta;
  sintheta = sqrt(1.-pow(costheta,2));
  if(sintheta>=0) theta = acos(costheta);
  else theta = -acos(costheta) + 2*TMath::Pi();

  if(costheta==1){
    cosphi=1; sinphi=0;
    phi=0;
  }
  else{
    cosphi = beta[0]/absbeta/sintheta;
    sinphi = beta[1]/absbeta/sintheta;
    if(sinphi>=0) phi = acos(cosphi);
    else phi = -acos(cosphi) + 2*TMath::Pi();
  }

  // -- Euler angle matrix definition
  double Ry[3][3] = {{ costheta,        0, sintheta},
		     {        0,        1,        0},
		     {-sintheta,        0, costheta}};
  double invRy[3][3] = {{costheta,        0, -sintheta},
			{       0,        1,         0},
			{sintheta,        0,  costheta}};
  double Rz[3][3] = {{cosphi, -sinphi, 0},
		     {sinphi,  cosphi, 0},
		     {       0,         0, 1}};
  double invRz[3][3] = {{cosphi, sinphi, 0},
			{-sinphi,cosphi, 0},
			{        0,       0, 1}};

  // transformation
  // S' -> S: (x) = Ry^[-1] Rz^[-1] (x')
  double dmy[3]={0}, mom_[3]={0};
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      dmy[i] += invRz[i][j] * mom[j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      mom_[i] += invRy[i][j] * dmy[j];
    }
  }

  // boost at z-direction in beta-direction-system
  mom_[2] = gamma*absbeta*Ene + gamma*mom_[2];

  // S -> S': (x') = Rz Ry (x)
  for(int i=0;i<3;i++){
    dmy[i]=0;
    mom[i]=0;	
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      dmy[i] += Ry[i][j] * mom_[j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      mom[i] += Rz[i][j] * dmy[j];
    }
  }

  // -- calc absolute momentum
  double absmom = 0;
  for(int i=0;i<3;i++)
    absmom += pow(mom[i],2);
  absmom = sqrt(absmom);

  Ene = sqrt(mass*mass + absmom*absmom);
  mom1=mom[0]; mom2=mom[1]; mom3=mom[2];
  
  return;
}
