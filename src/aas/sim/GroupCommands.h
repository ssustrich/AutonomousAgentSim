#pragma once

#include "aas\math\Vector3.h"

// Broadcast to the swarm as a whole
struct FormationMoveCommand
{
    Vector3 formationReferencePosition;   // e.g., centroid
    Vector3 formationVelocity;            // optional
};
