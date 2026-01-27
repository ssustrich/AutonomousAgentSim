#include "Formulas.h"
#include "Vec.h"
#include <math.h>

    Vec2 Formulas::velocityVec(float speed, float angle) {
        float dx = speed * cos(angle);
        float dy = speed * sin(angle);
        return Vec2(dx, dy);
    }

