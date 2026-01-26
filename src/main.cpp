#include <iostream>
#include "aas\math\Vector3.h"
#include "aas\sim\SimulationConfig.h"
#include "aas\sim\Simulation.h"

int main() {
    std::cout << "Milestone 0" << std::endl;

    constexpr float WORLD_XY_HALF_EXTENT_M = 100.0f;
    constexpr float WORLD_Z_MIN_M          = 0.0f;
    constexpr float WORLD_Z_MAX_M          = 50.0f;
    constexpr float NEIGHBOR_RADIUS = 60.0f;
    constexpr float SEPERATION_RADIUS = 15.0f;
    constexpr float MAX_SPEED = 80.0f;
    constexpr float MIN_SPEED = 40.0f;
    constexpr float MAX_FORCE = 50.0f;
    constexpr float MAX_ACCELERATION = 1.0f;
    constexpr float SEPERATION_WEIGHT = 1.5f;
    constexpr float ALIGNMENT_WEIGHT = 1.0f;
    constexpr float COHESION_WEIGHT = 1.0f;
    constexpr float DELTA_TIME  = 1.0f/60.0f;
    const Vector3 WORLD_MIN{-WORLD_XY_HALF_EXTENT_M, -WORLD_XY_HALF_EXTENT_M, WORLD_Z_MIN_M};
    const Vector3 WORLD_MAX{ WORLD_XY_HALF_EXTENT_M,  WORLD_XY_HALF_EXTENT_M, WORLD_Z_MAX_M};
    const int AGENT_COUNT = 100;
    
    SimulationConfig simulationConfig;
    simulationConfig.agentCount = AGENT_COUNT;
    simulationConfig.worldMax = WORLD_MAX;
    simulationConfig.worldMin = WORLD_MIN;
    simulationConfig.neighborRadius = NEIGHBOR_RADIUS;
    simulationConfig.dt = DELTA_TIME;
    simulationConfig.alignmentWeight = ALIGNMENT_WEIGHT;
    simulationConfig.seperationWeight = SEPERATION_WEIGHT;
    simulationConfig.cohesionWeight = COHESION_WEIGHT;
    simulationConfig.maxAccel = MAX_ACCELERATION;
    simulationConfig.maxForce = MAX_FORCE;
    simulationConfig.minSpeed = MIN_SPEED;
    simulationConfig.maxSpeed = MAX_SPEED;


    Simulation sim(simulationConfig);

    if (!sim.Initialize()){
        return EXIT_FAILURE;
    }


    sim.run();

    return 0;






}


