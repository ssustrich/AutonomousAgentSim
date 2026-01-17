#pragma once

#include <vector>
#include <cstddef>

#include "aas\math\Vector3.h"
#include "aas\math\Setpoint.h"
#include "GroupCommands.h"

class SwarmController
{
public:
    SwarmController();

    // Define formation slots (one per drone)
    void SetFormationSlots(const std::vector<Vector3>& slotOffsets);

    // Broadcast a group-level command and compute per-drone setpoints
    std::vector<Setpoint> ComputeSetpoints(
        const FormationMoveCommand& command
    ) const;

    std::size_t GetFormationSize() const;

private:
    // Offsets from formation reference, world-aligned for now
    std::vector<Vector3> slotOffsets_;
};
