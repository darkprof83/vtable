#include "plugin.hpp"
#include "pascalunit.hpp"

void APIENTRY Plugin::free ()
{
  IPlugin_release (thisPascal);
}

void APIENTRY Plugin::print ()
{
  IPlugin_print (thisPascal);
}

Plugin::Plugin ()
{
  thisPascal = IPlugin_getNewPlugin ();
}

Plugin::~Plugin ()
{

}

extern "C" IPlugin* APIENTRY getNewPlugin ()
{
  Plugin* plugin = new Plugin ();
  return plugin;
}
