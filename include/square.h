#pragma once

#include "vector.h"
#include "intersectable.h"

typedef struct _square Square_t;
typedef Square_t *Square;

Square create_square(Vector top_left, Vector bot_right);

int get_square_intersection(Square square, Vector origin, Vector direction);

void delete_square(Square square);
