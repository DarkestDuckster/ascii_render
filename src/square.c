#include <stdlib.h>

#include "square.h"

typedef struct _square {
    Intersectable intersect_base;
    Vector top_right;
    Vector bot_left; 
    Vector normal;
} Square_t;

Intersectable_f INTERSECT_FUNCTIONS = {(IntersectFunction_t) get_square_intersection};

Square
create_square(Vector top_right, Vector bot_left)
{
    Square_t *new_square = malloc(sizeof(Square_t));
    new_square->intersect_base = init_intersectable(&INTERSECT_FUNCTIONS);
    new_square->top_right = top_right;
    new_square->bot_left = bot_left;
    new_square->normal = create_zero_vector();
    return new_square;
}

int
get_square_intersection(Square square, Vector origin, Vector direction)
{
    if (origin.x >= square->top_right.x &&
        origin.y >= square->top_right.y &&
        origin.x < square->bot_left.x &&
        origin.y < square->bot_left.y)
        return 1;
    return 0;
}

void
delete_square(Square square)
{
    printf("Deleting Square\n");
    free(square);
}
