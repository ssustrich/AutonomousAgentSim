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
    std::uniform_int_distribution<int> randomInt(1, 10000);


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
   
        //Are there beter ways to do this? Probably, but who doesnt like a nice lamda function
         auto random_component = [&]() -> float {
             int r = randomInt(engine);
             return ((r % 100000) / 1.0f);
         };

//     auto random_vector3 = [=]() -> Vector3 {
//         auto component = [&]() -> float {
//             int r = random_int();
//             return (r * scale + offset) / divisor;
//         };

//         return Vector3{
//             component(),
//             component(),
//             component()
//         };
// };


        //When we create a boid it gets a random speed and range
        Boid b(x, random_heading, random_speed); 

        Vector3 v;
        v.x = random_component();
        v.y = random_component();
        v.z = random_component();

        b.setLocation(v);
        boids_.push_back(b);
    }

     //for (const Boid& b : boids_)
     //{
     //    std::cout << b << std::endl;
     //}

    return true;
}

bool Simulation::run(){
     
   for (auto& b : boids_){
        b.findNeighbors(config_.neighborRadius, boids_);
   }

   for (Boid b : boids_) {
       b.reactToNeighbors();
   }

   return true;

}

bool Simulation::ValidateWorld() const
{
    return false;
}

