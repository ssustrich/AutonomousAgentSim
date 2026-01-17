#include "Simulation.h"
#include "SimulationConfig.h"
#include <iostream>


Simulation::Simulation(const SimulationConfig& config)
    : config_(config)
{

}
bool Simulation::Initilizel()
{
    if ((config_.droneCount<1) || 
        (config_.worldMax.x > config_.worldMin.x) ||
        (config_.worldMax.y > config_.worldMin.y) ||
        (config_.worldMax.z > config_.worldMin.z)){
            std::cout << "Config invalid" << std::endl;
            return false;
        }

    std::cout << "Config valid" << std::endl;    
    return true;
}

bool Simulation::ValidateWorld() const
{
    return false;
}

