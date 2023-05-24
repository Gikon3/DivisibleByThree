cmake_minimum_required(VERSION 3.8)

project("DivisibleByThree")

add_executable(DivisibleByThree "src/main.cpp"  "src/divisibleByThreeResolve.cpp" "src/divisibleByThreeResolve.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DivisibleByThree PROPERTY CXX_STANDARD 20)
endif()
