#include <stdlib.h>

#include "square.h"

typedef struct _square {
    INTERSECT_BASE;
    Vector top_right;
    Vector bot_left; 
    Vector normal;
} Square_t;

DECLARE_INTERSECT_FUNCTIONS(SQUARE, get_square_intersection);

Square
create_square(Vector top_right, Vector bot_left)
{
    Square_t *new_square = malloc(sizeof(Square_t));
    INIT_INTERSECT_BASE(SQUARE, new_square);
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
    free(square);
}
