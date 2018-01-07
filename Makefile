coff: coff.o libplugin.so
	g++ -std=c++11 -Wno-attributes -o vtable -L. -Wl,-rpath-link,. -lplugin coff.o

libplugin.so: plugin.o 
	g++ -std=c++11 -Wno-attributes -o libplugin.so -L. -lpascalunit -shared plugin.o
	
plugin.o: plugin.cpp plugin.hpp libpascalunit.so
	g++ -std=c++11 -Wno-attributes -L. -lpascalunit -fPIC -c plugin.cpp
	
coff.o: coff.cpp pascalunit.hpp
	g++ -std=c++11 -Wno-attributes -c coff.cpp

libpascalunit.so: pascalunit.pas
	fpc -fPIC pascalunit.pas

clean:
	rm -f *.o *.ppu *.so vtable
