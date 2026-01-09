
# pycc/CMakeLists.txt
execute_process( COMMAND ${Python3_EXECUTABLE} -c "import numpy; print(numpy.get_include())"
    OUTPUT_VARIABLE NumPy_INCLUDE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE )

message(STATUS "NumPy include dir: ${NumPy_INCLUDE_DIR}")



# Create the pyodx C extension   
add_library(pyodx   MODULE  main.c  )

# Inclure les headers Python + headers ODB
target_include_directories(pyodx  PRIVATE
    ${Python3_INCLUDE_DIRS}
    ${NumPy_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/pyodx/include
)


#target_link_directories(pyodb  PRIVATE ${CMAKE_BINARY_DIR}/home/idehmous/Desktop/pkg/conda/envs/wradlib/lib/python3.9/site-packages/pyodb/lib )

target_link_libraries  (pyodx  PRIVATE odb_lib )

# Nom propre pour module Python (.so)
set_target_properties(pyodx  PROPERTIES
    OUTPUT_NAME "pyodx"
    PREFIX ""                
    BUILD_RPATH "\$ORIGIN/lib"
    INSTALL_RPATH "\$ORIGIN/lib"
)

# Install  
install(TARGETS pyodx LIBRARY DESTINATION  . )

install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/pyodx_extra/
  DESTINATION pyodx_extra
  FILES_MATCHING PATTERN "*.py"
)

