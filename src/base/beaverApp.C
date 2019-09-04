#include "beaverApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<beaverApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

beaverApp::beaverApp(InputParameters parameters) : MooseApp(parameters)
{
  beaverApp::registerAll(_factory, _action_factory, _syntax);
}

beaverApp::~beaverApp() {}

void
beaverApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"beaverApp"});
  Registry::registerActionsTo(af, {"beaverApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
beaverApp::registerApps()
{
  registerApp(beaverApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
beaverApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  beaverApp::registerAll(f, af, s);
}
extern "C" void
beaverApp__registerApps()
{
  beaverApp::registerApps();
}
