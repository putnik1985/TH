//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "DomainIC.h"

registerMooseObject("DomainApp", DomainIC);

InputParameters
DomainIC::validParams()
{
  InputParameters params = InitialCondition::validParams();
  params.addRequiredParam<Real>("T_domain", "Domain value of the initial condition");
  params.addRequiredParam<Real>("T_subdomain", "Subdomain value of the initial condition");
  return params;
}

DomainIC::DomainIC(const InputParameters & parameters)
  : InitialCondition(parameters), 
    T_domain(getParam<Real>("T_domain")),
    T_subdomain(getParam<Real>("T_subdomain"))
{
}

// This is the primary function custom ICs must implement.
Real
DomainIC::value(const Point & p)
{
  Real x = p(0);
  Real y = p(1);

  if (x<=4./3. && x>=2./3. && y<=5./6. && y>=1./6.){
      return T_subdomain;
  } else {
      return T_domain;
  }
}
