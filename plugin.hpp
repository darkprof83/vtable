#pragma once

#include "ApiEntry.hpp"

class IPlugin
{
public:
  virtual void APIENTRY free () = 0;
  virtual void APIENTRY print () = 0;
};

class Plugin : public IPlugin
{
public:
  virtual void APIENTRY free ();
  virtual void APIENTRY print ();
  void APIENTRY setPascalThis (void* thisPascal); 
  
private:
  void* thisPascal;
};

extern "C" IPlugin* APIENTRY getNewPlugin ();
