#include "circle.h"
#include <stdlib.h>

typedef struct _circle {
    Vector center;
    Vector radius;
} Circle_t;

Circle
create_circle(Vector center, Vector radius)
{
    Circle_t *new_circle = malloc(sizeof(Circle_t));
    new_circle->center = center;
    new_circle->radius = radius;

    return new_circle;
}

void
delete_circle(Circle circle)
{
    free(circle);
}
