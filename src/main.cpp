#include <iostream>
#include "aas\math\Vector3.h"
#include "aas\sim\SimulationConfig.h"
#include "aas\sim\Simulation.h"

int main() {
    std::cout << "Milestone 0" << std::endl;

    constexpr float WORLD_XY_HALF_EXTENT_M = 100.0f;
    constexpr float WORLD_Z_MIN_M          = 0.0f;
    constexpr float WORLD_Z_MAX_M          = 50.0f;

    const Vector3 WORLD_MIN{-WORLD_XY_HALF_EXTENT_M, -WORLD_XY_HALF_EXTENT_M, WORLD_Z_MIN_M};
    const Vector3 WORLD_MAX{ WORLD_XY_HALF_EXTENT_M,  WORLD_XY_HALF_EXTENT_M, WORLD_Z_MAX_M};

    const int NUM_OF_DRONES = 1;
    
    SimulationConfig simulationConfig;
    simulationConfig.droneCount = NUM_OF_DRONES;
    simulationConfig.worldMax = WORLD_MAX;
    simulationConfig.worldMin = WORLD_MIN;

    Simulation sim(simulationConfig);

    if (!sim.Initilizel())
        return EXIT_FAILURE;

    return 0;






}