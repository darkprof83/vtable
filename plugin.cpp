#include "plugin.hpp"
#include "pascalunit.hpp"
#include <iostream>

void APIENTRY Plugin::free ()
{
  // do not add code to this function
  delete this;
}

void APIENTRY Plugin::print ()
{
  IPlugin_print (thisPascal);
}

Plugin::Plugin ()
{
  std::cout << "Plugin::Plugin" << std::endl;
  thisPascal = IPlugin_getNewPlugin ();
}

Plugin::~Plugin ()
{
  IPlugin_release (thisPascal);
  std::cout << "Plugin::~Plugin" << std::endl;
}

// use the free () method to remove this plugin in your system code or better use smart pointers
// plugin1.reset ((IPlugin*)::getNewPlugin (), std::mem_fn ( &IPlugin::free ));
extern "C" IPlugin* APIENTRY getNewPlugin ()
{
  Plugin* plugin = new Plugin ();
  return plugin;
}
