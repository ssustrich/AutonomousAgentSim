#include "Simulation.h"
#include "SimulationConfig.h"
#include "aas\math\Vec.h"
#include "aas\math\Formulas.h"
#include <iostream>
#include <random> // Required for random number generation
#include <iomanip> // For std::fixed and std::setprecision
#include <chrono>
#include <cmath> // Required for std::round

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;

Simulation::Simulation(const SimulationConfig& config)
    : config_(config)   
{

}
bool Simulation::Initialize()
{
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 engine(seed);
    std::uniform_int_distribution<int> randomInt(1, 10000);

    std::uniform_int_distribution<int> rHeadingRange(1, 360);
    std::uniform_int_distribution<int> rSpeedRange(0, 100);
    std::setprecision(2);

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
        Vec2 vel =  Formulas::velocityVec(random_heading, random_speed);
        Boid b(x, vel); 

        Vec3 v;
        v.x() = random_component();
        v.y() = random_component();
        v.z() = random_component();

        b.setLocation(v);
        boids_.push_back(b);
    }


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

