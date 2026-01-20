#include "Simulation.h"
#include "SimulationConfig.h"
#include <iostream>
#include <random> // Required for random number generation
#include <iomanip> // For std::fixed and std::setprecision
#include <__msvc_chrono.hpp>
#include <cmath> // Required for std::round


Simulation::Simulation(const SimulationConfig& config)
    : config_(config)
{

}
bool Simulation::Initialize()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 engine(seed);
    std::uniform_int_distribution<int> rHeadingRange(1, 360);
    std::uniform_int_distribution<int> rSpeedRange(0, 100);
    std::setprecision(2);

    // if ((config_.agentCount<1) || 
    //     (config_.worldMax.x > config_.worldMin.x) ||
    //     (config_.worldMax.y > config_.worldMin.y) ||
    //     (config_.worldMax.z > config_.worldMin.z)){
    //         std::cout << "Config invalid" << std::endl;
    //         return false;
    //     }

    std::cout << "Config valid" << std::endl;    
 
    for (std::int16_t x =0; x<config_.agentCount; x++){

        int random_speed = rSpeedRange(engine);
        int random_heading = rHeadingRange(engine);
        //When we create a boid it gets a random speed and range
        Boid b(x, random_heading, random_speed); 
        boids_.push_back(b);
    }

    for (const Boid& b : boids_)
    {
        std::cout << b << std::endl;
    }

    return true;
}





bool Simulation::ValidateWorld() const
{
    return false;
}

