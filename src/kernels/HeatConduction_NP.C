//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "HeatConduction_NP.h"

registerMooseObject("THApp", HeatConduction_NP);

InputParameters
HeatConduction_NP::validParams()
{
  auto params = ADKernelGrad::validParams();
  params.addClassDescription("Same as `Diffusion` in terms of physics/residual, but the Jacobian "
                             "is computed using forward automatic differentiation");

  params.addRequiredParam<Real>("heat_conduction", "heat_conduction");
  return params;
}

HeatConduction_NP::HeatConduction_NP(const InputParameters & parameters) : 
ADKernelGrad(parameters),
heat_conduction(getParam<Real>("heat_conduction"))
{}

ADRealVectorValue
HeatConduction_NP::precomputeQpResidual()
{
  return heat_conduction * _grad_u[_qp];
}
