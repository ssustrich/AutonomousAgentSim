#pragma once

#include <cstddef>
#include "aas\math\Vector3.h"
#include "aas\sim\Commands.h"
#include <ostream>

#ifndef BOID_H
#define BOID_H
class Boid
{
    public:
    Boid(std::int16_t id, int heading, int speed);
    std::int16_t GetId() const;
    int GetSpeed() const;
    int GetHeading() const;
    float heading, speed;
 //   Boid(std::int16_t id, const float& heading, const float& speed);

    private:
    friend std::ostream& operator<<(std::ostream& os, const Boid& boid);
    std::int16_t _id;
    int _heading;
    int _speed;

};
#endif // BOID_H
