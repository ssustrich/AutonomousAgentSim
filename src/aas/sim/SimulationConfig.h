#pragma once

#include "aas\math\Vector3.h"

struct SimulationConfig
{
    // Placeholder for future:
    // fixed timestep, determinism flags, logging, etc.
    int droneCount = 0; 
    Vector3 worldMin;
    Vector3 worldMax;

};
