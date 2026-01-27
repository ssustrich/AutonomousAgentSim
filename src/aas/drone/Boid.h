#pragma once

#include <vector>
#include <cstddef>
#include "aas\math\Vec.h"
#include "aas\sim\Commands.h"
#include <ostream>

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;

#ifndef BOID_H
#define BOID_H
class Boid
{
    public:
    //Boid(std::int16_t id, int heading, int speed);
    Boid(std::int16_t id, Vec2  velocity);
    std::int16_t getId();
    //int getSpeed() const;
    //int getHeading() const;
    //void setSpeed( int newSpeed);
    //void setHeading( int newHeading);
    Vec3 getLocation();
    Vec2 getVelocity();
    void setLocation(Vec3 newLocation);
    void reactToNeighbors();
    void findNeighbors(float range, std::vector<Boid> boids_);

    private:
    friend std::ostream& operator<<(std::ostream& os, const Boid& boid);
    std::vector<Boid> neighbors;
    std::int16_t _id;
    //int _heading;
    //int _speed;
    Vec3 _location;
    Vec2 _velocity;
};
#endif // BOID_H
