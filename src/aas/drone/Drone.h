#pragma once

#include <cstddef>
#include "aas\math\Vector3.h"
#include "aas\sim\Commands.h"


class Drone
{
public:
    explicit Drone(std::size_t id);

    std::size_t GetId() const;

    void ApplyMoveCommand(const MoveCommand& command);

    const Vector3& GetDesiredVelocity() const;

private:
    std::size_t id_{0};

    Vector3 desiredVelocity_{};
};
