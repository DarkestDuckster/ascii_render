#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>

// -------------
//  Vector Creation
// -------------

Vector_t
create_zero_vector(void)
{
    return create_new_vector(0, 0, 0);
}

Vector_t
create_new_vector(float x, float y, float z)
{
    Vector new_vector;
    new_vector.x = x;
    new_vector.y = y;
    new_vector.z = z;
    return new_vector;
}

// -------------
//  Vector Math
// -------------

Vector_t
add_vectors(Vector_t vector_a, Vector_t vector_b)
{
    float new_x = vector_a.x + vector_b.x;
    float new_y = vector_a.y + vector_b.y;
    float new_z = vector_a.z + vector_b.z;
    return create_new_vector(new_x, new_y, new_z);
}

Vector_t
sub_vectors(Vector_t vector_a, Vector_t vector_b)
{
    float new_x = vector_a.x - vector_b.x;
    float new_y = vector_a.y - vector_b.y;
    float new_z = vector_a.z - vector_b.z;
    return create_new_vector(new_x, new_y, new_z);
}

Vector_t
cross_product(Vector_t vector_a, Vector_t vector_b)
{
    Vector_t return_vector = create_zero_vector();

    return_vector.x = vector_a.y * vector_b.z - vector_a.z * vector_b.y;
    return_vector.y = vector_a.z * vector_b.x - vector_a.x * vector_b.z;
    return_vector.z = vector_a.x * vector_b.y - vector_a.y * vector_b.x;

    return return_vector;
}

float
dot_product(Vector_t vector_a, Vector_t vector_b)
{
    float dot_value = 0.f;

    dot_value += vector_a.x * vector_b.x;
    dot_value += vector_a.y * vector_b.y;
    dot_value += vector_a.z * vector_b.z;

    return dot_value;
}

// -------------
//  Vector Utility
// -------------

void
print_vector(Vector_t vector)
{
    printf("Vector{x:%03f, y:%03f, z:%03f}\n", vector.x, vector.y, vector.z);
}
