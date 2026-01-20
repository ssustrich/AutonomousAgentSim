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
)

# Allow includes like: #include "math/Vector3.h"
target_include_directories(AutonomousAgentSim PRIVATE src)

# ---- Compiler warnings ----
if (MSVC)
    target_compile_options(AutonomousAgentSim PRIVATE /W4 /permissive-)
else()
    target_compile_options(AutonomousAgentSim PRIVATE -Wall -Wextra -Wpedantic)
endif()