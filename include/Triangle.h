#pragma once
#include "Vector.h"

typedef struct _triangle {
    Vector_t A, B, C;
    Vector_t _A, _B, _C;
} Triangle;

typedef Triangle *Triangle_t;

Triangle_t 
create_new_triangle(int A_x, int A_y,
                    int B_x, int B_y,
                    int C_x, int C_y);

void rotate_triangle_y(Triangle_t triangle, float rotation_amount);


int is_vector_in_triangle(Vector_t vector, Triangle_t triangle);
void delete_triangle(Triangle_t triangle);

