#pragma once

extern "C"
{
  void* IPlugin_getNewPlugin ();
  void IPlugin_release (void* thisPascal);
  void IPlugin_print (void* thisPascal);
}
