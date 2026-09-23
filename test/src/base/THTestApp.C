//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "THTestApp.h"
#include "THApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
THTestApp::validParams()
{
  InputParameters params = THApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

THTestApp::THTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  THTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

THTestApp::~THTestApp() {}

void
THTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  THApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"THTestApp"});
    Registry::registerActionsTo(af, {"THTestApp"});
  }
}

void
THTestApp::registerApps()
{
  registerApp(THApp);
  registerApp(THTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
THTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  THTestApp::registerAll(f, af, s);
}
extern "C" void
THTestApp__registerApps()
{
  THTestApp::registerApps();
}
