#pragma once

#include <vector>
#include <cstddef>

#include "aas\drone\Drone.h"
#include "aas\sim\World.h"
#include "SimulationConfig.h"

class Simulation
{
public:
    explicit Simulation(const SimulationConfig& config);

    // World construction
    bool Initilizel();

    // Execution
    bool StepOne();
    bool StepN(std::size_t numSteps);

private:
    bool ValidateWorld() const;

private:
    SimulationConfig config_;

    WorldBounds worldBounds_{};
    std::vector<Drone> drones_;

    bool worldInitialized_{false};
};
