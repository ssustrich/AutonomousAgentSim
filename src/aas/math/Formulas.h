// Formulas.h
#ifndef FORMULAS_H
#define FORMULAS_H
#include "Vec.h"

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;

class Formulas
{
public:
    static Vec2 velocityVec(float speed, float angle);
private:
    static float dx, dy;
};

#endif // FORMULAS_H