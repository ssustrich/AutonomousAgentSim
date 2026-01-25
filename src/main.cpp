#include <iostream>
#include "aas\math\Vector3.h"
#include "aas\sim\SimulationConfig.h"
#include "aas\sim\Simulation.h"

int main() {
    std::cout << "Milestone 0" << std::endl;

    constexpr float WORLD_XY_HALF_EXTENT_M = 100.0f;
    constexpr float WORLD_Z_MIN_M          = 0.0f;
    constexpr float WORLD_Z_MAX_M          = 50.0f;
    constexpr float CHECK_RANGE = 1000.0f;

    const Vector3 WORLD_MIN{-WORLD_XY_HALF_EXTENT_M, -WORLD_XY_HALF_EXTENT_M, WORLD_Z_MIN_M};
    const Vector3 WORLD_MAX{ WORLD_XY_HALF_EXTENT_M,  WORLD_XY_HALF_EXTENT_M, WORLD_Z_MAX_M};

    const int AGENT_COUNT = 100;
    
    SimulationConfig simulationConfig;
    simulationConfig.agentCount = AGENT_COUNT;
    simulationConfig.worldMax = WORLD_MAX;
    simulationConfig.worldMin = WORLD_MIN;
    simulationConfig.neighborRadius = CHECK_RANGE;

    Simulation sim(simulationConfig);

    if (!sim.Initialize()){
        return EXIT_FAILURE;
    }


    sim.run();

    return 0;






}


