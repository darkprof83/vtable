# clean-all.cmake
set(cmake_generated ${CMAKE_BINARY_DIR}/ledisasm/CMakeCache.txt
                    ${CMAKE_BINARY_DIR}/ledisasm/cmake_install.cmake
                    ${CMAKE_BINARY_DIR}/ledisasm/ledisasmConfig.hpp.gch
                    ${CMAKE_BINARY_DIR}/ledisasm/ledisasmConfig.hpp
                    ${CMAKE_BINARY_DIR}/ledisasm/Makefile
                    ${CMAKE_BINARY_DIR}/ledisasm/CMakeFiles
                    
                    ${CMAKE_BINARY_DIR}/libLE/CMakeCache.txt
                    ${CMAKE_BINARY_DIR}/libLE/cmake_install.cmake
                    ${CMAKE_BINARY_DIR}/libLE/libLEConfig.hpp.gch
                    ${CMAKE_BINARY_DIR}/libLE/libLEConfig.hpp
                    ${CMAKE_BINARY_DIR}/libLE/Makefile
                    ${CMAKE_BINARY_DIR}/libLE/CMakeFiles
                    
                    ${CMAKE_BINARY_DIR}/CMakeCache.txt
                    ${CMAKE_BINARY_DIR}/cmake_install.cmake  
                    ${CMAKE_BINARY_DIR}/Makefile
                    ${CMAKE_BINARY_DIR}/CMakeFiles
)

foreach(file ${cmake_generated})

  if (EXISTS ${file})
     file(REMOVE_RECURSE ${file})
  endif()

endforeach(file)
