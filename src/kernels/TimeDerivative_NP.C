//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "TimeDerivative_NP.h"

registerMooseObject("THApp", TimeDerivative_NP);

InputParameters
TimeDerivative_NP::validParams()
{
  InputParameters params = ADTimeKernelValue::validParams();
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial u_h}{\\partial t})$.");
  params.addRequiredParam<Real>("density", "density");
  params.addRequiredParam<Real>("heat_capacity", "heat capacity");
  return params;
}

TimeDerivative_NP::TimeDerivative_NP(const InputParameters & parameters)
  : ADTimeKernelValue(parameters),
    density(getParam<Real>("density")),
    heat_capacity(getParam<Real>("heat_capacity"))
{
}

ADReal
TimeDerivative_NP::precomputeQpResidual()
{
  return density * heat_capacity * _u_dot[_qp];
}
