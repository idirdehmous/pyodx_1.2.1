
# Main CMakeFiles.txt 
cmake_minimum_required(VERSION 3.15)
project(pyodx LANGUAGES C CXX)


# Force position-independent code for shared libs
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# Scikit-build provides Python variables
find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)



# Include ecmwf macros 
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set ( MACROS_DIR     ${CMAKE_SOURCE_DIR}/cmake   )                                  
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")                  
list(APPEND ${CMAKE_MODULE_PATH}    ${MACROS_DIR}      ) 

include(ecbuild_system)
include(odb_add_schema)
include(odb_link_schemas)
include(odb_set_environment)



# Compilation 
add_subdirectory(odb)      # produce libodb.so  
add_subdirectory(pycc)



# __init__ 
install( FILES  ${CMAKE_SOURCE_DIR}/__init__.py     DESTINATION   . )

# Pure python : pyodb_extra
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/pyodx_extra/
  DESTINATION pyodx_extra
  FILES_MATCHING PATTERN "*.py"
)

# ODB  (Relatively to scikit.build)  
install(DIRECTORY bin     DESTINATION bin     OPTIONAL)
install(DIRECTORY include DESTINATION include OPTIONAL)
install(DIRECTORY lib     DESTINATION lib     OPTIONAL)
install(DIRECTORY share   DESTINATION share   OPTIONAL)
install(DIRECTORY module  DESTINATION module  OPTIONAL)

