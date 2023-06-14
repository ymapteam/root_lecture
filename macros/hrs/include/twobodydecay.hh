void twobodydecay(double parentM,
                  double &daughterM1, double &daughterP1,
                  double &daughterM2, double &daughterP2
                  ){
    daughterP1 = sqrt( pow( (pow(parentM,2)
                            - pow(daughterM1,2)
                            + pow(daughterM2,2))
                           /(2*parentM),2)
                      -pow(daughterM2,2));
    daughterP2 = daughterP1;
    return;
}
