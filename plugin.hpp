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

extern "C" IPlugin* APIENTRY getNewPlugin ();
