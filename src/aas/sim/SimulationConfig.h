#pragma once

#include "aas\math\Vector3.h"

struct SimulationConfig
{
    // Placeholder for future:
    // fixed timestep, determinism flags, logging, etc.
    int agentCount = 0;
    Vector3 worldMin, worldMax;
    float dt, maxSpeed, maxAccel, neighborRadius, separationRadius;
    float wSeparation, wAlignment, wCohesion;   
    enum boundaryBehavior {
        Wrap, Bounce
    };


};
