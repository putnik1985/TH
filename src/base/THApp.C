#include "THApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
THApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

THApp::THApp(const InputParameters & parameters) : MooseApp(parameters)
{
  THApp::registerAll(_factory, _action_factory, _syntax);
}

THApp::~THApp() {}

void
THApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<THApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"THApp"});
  Registry::registerActionsTo(af, {"THApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
THApp::registerApps()
{
  registerApp(THApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
THApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  THApp::registerAll(f, af, s);
}
extern "C" void
THApp__registerApps()
{
  THApp::registerApps();
}
