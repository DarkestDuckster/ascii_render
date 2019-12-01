#pragma once
#include "Vector.h"

typedef struct _triangle {
    // Actual location of points
    Vector_t A, B, C;
    // Original location stored as center + offset
    Vector_t center;
    Vector_t A_offset, B_offset, C_offset;
    // Updates to be applied
    Vector_t translation;
    Vector_t rotation;
    Vector_t scale;
} Triangle;

typedef Triangle *Triangle_t;

Triangle_t 
create_new_triangle(float A_x, float A_y, float A_z,
                    float B_x, float B_y, float B_z,
                    float C_x, float C_y, float C_z);

void set_triangle_translation(Triangle_t, Vector_t translation);
void set_triangle_rotation(Triangle_t, Vector_t rotation);
void set_triangle_scale(Triangle_t, Vector_t scale);

void apply_triangle_rotation(Triangle_t triangle);

int is_vector_in_triangle(Vector_t vector, Triangle_t triangle);
void delete_triangle(Triangle_t triangle);

