# CMakeList.txt : CMake project for OOP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OOP")

# Add source to this project's executable.
add_executable (OOP "OOP.cpp" "funkcijos.h" "funkcijos.cpp" "studentas.h" "studentas.cpp" "Vector.hpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OOP PROPERTY CXX_STANDARD 20)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(OOP PRIVATE "-O3")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(OOP PRIVATE "/O3")
endif()

target_compile_features(OOP PRIVATE cxx_std_20)
