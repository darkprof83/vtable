#pragma once

#include "ApiEntry.hpp"

class IBasePlugin
{
public:
  virtual void APIENTRY free () = 0;
};

class IPlugin : public IBasePlugin
{
public:
  virtual void APIENTRY print () = 0;
};

class Plugin : public IPlugin
{
public:
  virtual void APIENTRY free ();
  virtual void APIENTRY print ();
  Plugin ();
  virtual ~Plugin ();
  
private:
  void* thisPascal;
};

// use the free () method to remove this plugin in your system code or better use smart pointers
// plugin1.reset ((IPlugin*)::getNewPlugin (), std::mem_fn ( &IPlugin::free ));
extern "C" IPlugin* APIENTRY getNewPlugin ();
