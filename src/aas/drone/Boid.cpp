#include <iostream>
#include <cstddef>
#include "aas\math\Vec.h"
#include "aas\sim\Commands.h"
#include "Boid.h"
#include <vector>
#include <string>

    Boid::Boid(std::int16_t id, Vec2 velocity)
    {
        this->_id = id;
        this->_velocity = velocity;
    }

    Vec3 Boid::getLocation(){
        return _location;
    }

    Vec2 Boid::getVelocity() {
        return _velocity;
    }

    std::int16_t Boid::getId() {
        return _id;
    }

    void Boid::setLocation(Vec3 newLocation)
    {
        _location = newLocation;
        //_location.y() = newLocation.y();
        //_location.z() = newLocation.z();
    }

    void Boid::reactToNeighbors() {
        std::cout << "Boid " << _id << " has a velocity of ("
            << _velocity[0] << "," << _velocity[1]
            << ")\n";
        if (neighbors.size() > 0) {
      
            //Avg out heading/Location/Speed
            Vec3 avgLocation = this->getLocation();
            Vec2 avgVelocity = this->getVelocity();
            
            
            for (Boid b : neighbors) {
                avgLocation.x() += b.getLocation().x();
                avgLocation.y() += b.getLocation().y();
                avgVelocity.x() += b.getVelocity().x();
                avgVelocity.y() += b.getVelocity().y();

            }
            _velocity.x() = avgVelocity.x() / (neighbors.size() + 1);
            _velocity.y() = avgVelocity.y() / (neighbors.size() + 1);
            _location.x() = avgLocation.x() / (neighbors.size() + 1);
            _location.y() = avgLocation.y() / (neighbors.size() + 1);
            std::cout << "Boid " << _id << " now has a velocity of ("
                << _velocity[0] << "," << _velocity[1]
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
        minX = _location[0] - range;
        maxX = _location[0] + range;
        minY = _location[1] - range;
        maxY = _location[1] + range;
        for ( Boid b : boids_) {
            if (b.getId() != this->getId()) {
                Vec3 bloc = b.getLocation();
                if (bloc[0] < maxX && bloc[0] > minX &&
                    bloc[1] < maxY && bloc[1] > minY) {
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
        os << "Boid{id=" << boid._id << ", has velocity=(" << boid._velocity.x() << "," << boid._velocity.y() <<
            ")\n Location<" << boid._location.x() <<","<< boid._location.y()  << "," << boid._location.z() << ">}";
        return os;
    }
