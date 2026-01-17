#pragma once

#include "aas\math\Vector3.h"

// Per-drone target produced by swarm logic
struct Setpoint
{
    Vector3 targetPosition;     // world-space
    Vector3 targetVelocity;     // optional; can be zero in Milestone 0
};
