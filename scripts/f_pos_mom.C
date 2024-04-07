//

//-----------------------------------------------------------------------------
double f_pos_mom(double* X, double* Par) {
  double dx = X[0]-55.;
  double f = Par[0]*exp(-Par[1]*dx*(1+dx*Par[2]));
  return f;
}
