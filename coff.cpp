#include "plugin.hpp"
#include <memory>
#include <functional>

int main (int argc, const char* argv[])
{
  std::shared_ptr<IPlugin> plugin1;
  std::shared_ptr<IPlugin> plugin2;
  
  plugin1.reset ((IPlugin*)::getNewPlugin (), std::mem_fn ( &IPlugin::free ));
  plugin1 -> print ();
  
  plugin2.reset ((IPlugin*)::getNewPlugin (), std::mem_fn ( &IPlugin::free ));
  plugin2 -> print ();
  
  return 0;
}
