#include <stdlib.h>

#include "square.h"

typedef struct _square {
    Intersectable intersect_base;
    Vector top_left;
    Vector bot_right; 
    Vector normal;
} Square_t;

Intersectable_f INTERSECT_FUNCTIONS = {(IntersectFunction_t) get_square_intersection};

Square
create_square(Vector top_left, Vector bot_right)
{
    Square_t *new_square = malloc(sizeof(Square_t));
    new_square->intersect_base = init_intersectable(&INTERSECT_FUNCTIONS);
    new_square->top_right = top_left;
    new_square->bot_left = bot_right;
    new_square->normal = create_zero_vector();
    return new_square;
}

int
get_square_intersection(Square square, Vector origin, Vector direction)
{
    Vector i = line_plane_intersection(create_zero_vector(), create_vector3(0, 0, -1),
                                       origin, direction);
    if (origin.x >= square->top_left.x &&
        origin.y >= square->top_left.y &&
        origin.x < square->bot_right.x &&
        origin.y < square->bot_right.y)
        return 1;
    return 0;
}

void
delete_square(Square square)
{
    printf("Deleting Square\n");
    free(square);
}
