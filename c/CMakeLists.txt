cmake_minimum_required(VERSION 3.17)
project(calculator C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        v2.6.0
)
FetchContent_MakeAvailable(unity)

# Enable double-precision support in Unity
target_compile_definitions(unity PUBLIC UNITY_INCLUDE_DOUBLE)

add_library(calculator src/calculator.c)
target_include_directories(calculator PUBLIC include)

enable_testing()
add_executable(test_calculator tests/test_calculator.c)
target_link_libraries(test_calculator calculator unity)
add_test(NAME calculator_tests COMMAND test_calculator)
