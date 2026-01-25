#include <iostream>
#include <cstddef>
#include "aas\math\Vector3.h"
#include "aas\sim\Commands.h"
#include "Boid.h"
#include <vector>
#include <string>



    Boid::Boid(std::int16_t id, int heading, int speed)
    {
        _id = id;
        _speed = speed;
        _heading = heading;
    }

    int Boid::GetSpeed() const
    {
        return _speed;
    }

    int Boid::GetHeading() const
    {
        return _heading;
    }

    Vector3 Boid::getLocation(){
        return _location;
    }

    std::int16_t Boid::GetId() {
        return _id;
    }

    void Boid::SetSpeed(int newSpeed)
    {
        _speed = newSpeed;

    }
    void Boid::SetHeading(int newHeading)
    {
        _heading = newHeading;
    }
    void Boid::setLocation(Vector3 newLocation)
    {
        _location = newLocation;
    }

    void Boid::reactToNeighbors() {
        std::cout << "Boid " << this->GetId() << " has a heading of " << this->GetHeading() << "\n";
        if (neighbors.size() > 0) {
            float avgHeading = this->GetHeading();
            Vector3 avgLocation = this->getLocation();
            for (Boid b : neighbors) {
                avgHeading += b.GetHeading();
                avgLocation.x += b.getLocation().x;
                avgLocation.y += b.getLocation().y;
            }
            _heading = avgHeading / (neighbors.size() + 1);
            _location.x = avgLocation.x / (neighbors.size() + 1);
            _location.y = avgLocation.y / (neighbors.size() + 1);
            std::cout << "Boid " << this->GetId() << " Now has a heading of " << this->GetHeading() << "\n";
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
            if (b.GetId() != this->GetId()) {
                Vector3 bloc = b.getLocation();
                if (bloc.x < maxX && bloc.x > minX &&
                    bloc.y < maxY && bloc.y > minY) {
                        std::cout << b.GetId() << std::endl;
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
        os << "Boid{id=" << boid._id << ", heading, speed=(" << boid._heading <<  "," <<  boid._speed <<
        ")\n Location<" << boid._location.x<<","<< boid._location.y<< "," << boid._location.z<< ">}";
        return os;
    }
