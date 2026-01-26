#pragma once

#include <vector>
#include <cstddef>
#include "aas\math\Vector3.h"
#include "aas\math\Vector2.h"
#include "aas\sim\Commands.h"
#include <ostream>

#ifndef BOID_H
#define BOID_H
class Boid
{
    public:
    //Boid(std::int16_t id, int heading, int speed);
    Boid(std::int16_t id, Vector2 velocity);
    std::int16_t getId();
    //int getSpeed() const;
    //int getHeading() const;
    //void setSpeed( int newSpeed);
    //void setHeading( int newHeading);
    Vector3 getLocation();
    Vector2 getVelocity();
    void setLocation(Vector3 newLocation);
    void reactToNeighbors();
    void findNeighbors(float range, std::vector<Boid> boids_);

    private:
    friend std::ostream& operator<<(std::ostream& os, const Boid& boid);
    std::vector<Boid> neighbors;
    std::int16_t _id;
    //int _heading;
    //int _speed;
    Vector3 _location;
    Vector2 _velocity;
};
#endif // BOID_H
