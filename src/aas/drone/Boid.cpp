#include <iostream>
#include <cstddef>
#include "aas\math\Vector3.h"
#include "aas\math\Vector2.h"
#include "aas\sim\Commands.h"
#include "Boid.h"
#include <vector>
#include <string>

    Boid::Boid(std::int16_t id, Vector2 velocity)
    {
        this->_id = id;
        this->_velocity = velocity;
    }

    Vector3 Boid::getLocation(){
        return _location;
    }

    Vector2 Boid::getVelocity() {
        return _velocity;
    }

    std::int16_t Boid::getId() {
        return _id;
    }

    void Boid::setLocation(Vector3 newLocation)
    {
        _location = newLocation;
    }

    void Boid::reactToNeighbors() {
        std::cout << "Boid " << this->getId() << " has a velocity of ("
            << this->getVelocity().x << "," << this->getVelocity().y
            << ")\n";
        if (neighbors.size() > 0) {
      
            //Avg out heading/Location/Speed
            Vector3 avgLocation = this->getLocation();
            Vector2 avgVelocity = this->getVelocity();
            
            
            for (Boid b : neighbors) {
                avgLocation.x += b.getLocation().x;
                avgLocation.y += b.getLocation().y;
                avgVelocity.x += b.getVelocity().x;
                avgVelocity.y += b.getVelocity().y;

            }
            _velocity.x = avgVelocity.x / (neighbors.size() + 1);
            _velocity.y = avgVelocity.y / (neighbors.size() + 1);
            _location.x = avgLocation.x / (neighbors.size() + 1);
            _location.y = avgLocation.y / (neighbors.size() + 1);
            std::cout << "Boid " << this->getId() << " Now has a velocity of ("
                << this->getVelocity().x << "," << this->getVelocity().y
                << ")\n";
        }
    }

    void Boid::findNeighbors(float range, std::vector<Boid> boids_){

        /*if (allBoidsPtr == nullptr) {
            std::cout << "Error: Null pointer provided." << std::endl;
            return;
        }*/

        // Dereference the pointer to get the actual vector
        float minX, maxX, minY, maxY;
        minX = _location.x - range;
        maxX = _location.x + range;
        minY = _location.y - range;
        maxY = _location.y + range;
        for ( Boid b : boids_) {
            if (b.getId() != this->getId()) {
                Vector3 bloc = b.getLocation();
                if (bloc.x < maxX && bloc.x > minX &&
                    bloc.y < maxY && bloc.y > minY) {
                        std::cout << b.getId() << std::endl;
                        neighbors.push_back(b);
                }
            }
            else { 
                continue; 
            }
        }
        //std::cout << "Boid " << this->GetId() << " has: " << neighbors.size() << "friends\n";
    }
    std::ostream& operator<<(std::ostream& os, const Boid& boid)
    {
        os << "Boid{id=" << boid._id << ", has velocity=(" << boid._velocity.x << "," << boid._velocity.y <<
            ")\n Location<" << boid._location.x<<","<< boid._location.y<< "," << boid._location.z<< ">}";
        return os;
    }
