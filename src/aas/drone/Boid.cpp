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

    std::ostream& operator<<(std::ostream& os, const Boid& boid)
{
    os << "Boid{id=" << boid._id << ", heading, speed=(" << boid._heading <<  "," <<  boid._speed <<")}";
    return os;
}

    



