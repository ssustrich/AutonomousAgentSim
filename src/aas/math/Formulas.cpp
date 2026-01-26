#include "Formulas.h"
#include "Vector2.h"
#include <math.h>

    Vector2 Formulas::velocityVec(float speed, float angle) {
        float dx = speed * cos(angle);
        float dy = speed * sin(angle);
        return Vector2(dx, dy);
    }

