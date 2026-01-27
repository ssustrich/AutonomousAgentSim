cmake_minimum_required(VERSION 3.20)

project(AutonomousAgentSim LANGUAGES CXX)

# ---- Language standard ----
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Executable ----
add_executable(AutonomousAgentSim
    src/main.cpp
    src/aas/sim/Simulation.cpp
    src/aas/drone/Boid.cpp
    src/aas/math/Formulas.cpp
)
# Allow includes like: #include "math/Vector3.h"
target_include_directories(AutonomousAgentSim PRIVATE src)



include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

# Prevent GoogleTest from overriding MSVC runtime settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(vec_tests
    tests/test_vec.cpp
)

target_include_directories(vec_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(vec_tests PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(vec_tests)


# ---- Compiler warnings ----
if (MSVC)
    target_compile_options(AutonomousAgentSim PRIVATE /W4 /permissive-)
    target_compile_options(vec_tests PRIVATE /W4 /permissive-)
else()
    target_compile_options(AutonomousAgentSim PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(vec_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

