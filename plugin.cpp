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

void APIENTRY Plugin::setPascalThis (void* thisPascal)
{
  this -> thisPascal = thisPascal;
}

extern "C" IPlugin* APIENTRY getNewPlugin ()
{
  Plugin* plugin = new Plugin ();
  plugin -> setPascalThis (IPlugin_getNewPlugin ());
  return plugin;
}
