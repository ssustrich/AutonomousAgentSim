#pragma once

#include "aas\math\Vector3.h"
#include "aas\math\SetPoint.h"

class FlightController
{
public:
    FlightController();

    // Receives a per-drone setpoint from swarm logic
    void ApplySetpoint(const Setpoint& setpoint);

    // Compute desired motion for this step
    // (Milestone 0: can be purely proportional or even direct assignment)
    void Update();

    // Output used by the Drone
    const Vector3& GetDesiredVelocity() const;

private:
    Setpoint currentSetpoint_{};

    Vector3 desiredVelocity_{};

    // Controller parameters (tunable later)
    double positionGain_{1.0};
    double maxSpeed_{10.0};
};
