#pragma once

#include <vector>
#include <cstddef>

#include "aas\drone\Boid.h"
#include "aas\sim\World.h"
#include "SimulationConfig.h"



class Simulation
{
public:
    explicit Simulation(const SimulationConfig& config);

    // World construction
    bool Initialize();

    // Execution
    bool StepOne();
    bool StepN(std::size_t numSteps);

    bool run();


private:
    SimulationConfig config_;
    WorldBounds worldBounds_{};
    bool worldInitialized_{false};
    bool ValidateWorld() const;
    
    std::vector<Boid> boids_;
    void update(float);
};
