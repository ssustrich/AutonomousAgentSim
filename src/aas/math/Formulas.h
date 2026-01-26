// Formulas.h
#ifndef FORMULAS_H
#define FORMULAS_H
#include "Vector2.h"


class Formulas
{
public:
    static Vector2 velocityVec(float speed, float angle);
private:
    static float dx, dy;
};

#endif // FORMULAS_H