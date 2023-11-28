#include <iostream>
#include <cmath>

#include "CDistNormal.h"

double CDistNormal::F(double _x)
{
  x = _x;
  y = 1./sqrt(2.*M_PI)*pow(M_E, - ((x*x)/2.));
  return y;
}

double CDistNormal::Area(double _x) 
{
  x = _x;
  area = 0.5*(1. - erf((- x) / sqrt(2.)));
  return area;
}

double CDistNormal::ErfInv(double x)      
{
  double m;
  m = 0.5*sqrt(M_PI)*(x + M_PI*x*x*x/12. + 7.*M_PI*M_PI*pow(x, 5)/480. + 127.*pow(M_PI, 3)*pow(x, 7)/40320. +
      4369.*pow(M_PI, 4)*pow(x, 9)/5806080. + 34807.*pow(M_PI, 5)*pow(x, 11)/182476800.);
  return m;
}

double CDistNormal::InvArea(double _x)
{
  area = _x; 
  x = - sqrt(2.)*(ErfInv(1. - (2.*area)));
  return x;
}
