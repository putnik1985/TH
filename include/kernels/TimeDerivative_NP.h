//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADTimeKernelValue.h"

class TimeDerivative_NP : public ADTimeKernelValue
{
public:
  static InputParameters validParams();

  TimeDerivative_NP(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;

private:
  Real heat_capacity;
  Real density;
};
