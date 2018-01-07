#include "plugin.hpp"
#include "pascalunit.hpp"
#include <iostream>

void APIENTRY Plugin::free ()
{
  IPlugin_release (thisPascal);
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
  std::cout << "Plugin::~Plugin" << std::endl;
}

extern "C" IPlugin* APIENTRY getNewPlugin ()
{
  Plugin* plugin = new Plugin ();
  return plugin;
}
