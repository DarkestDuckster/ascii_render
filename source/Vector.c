#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector_t
create_zero_vector(void)
{
    return create_new_vector(0, 0, 0);
}

Vector_t
create_new_vector(int x, int y, int z)
{
    Vector *new_vector = malloc(sizeof(Vector));
    new_vector->x = x;
    new_vector->y = y;
    new_vector->z = z;
    return new_vector;
}

void
delete_vector(Vector_t vector)
{
    free(vector);
}

void
print_vector(Vector_t vector)
{
    printf("Vector{x:%03d, y:%03d}\n", vector->x, vector->y);
}
