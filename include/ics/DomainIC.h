//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

// MOOSE Includes
#include "InitialCondition.h"

class DomainIC : public InitialCondition
{
public:
  DomainIC(const InputParameters & parameters);
  static InputParameters validParams();

  virtual Real value(const Point & p) override;

private:
  const Real T_domain;
  const Real T_subdomain;
};
