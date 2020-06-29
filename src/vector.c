#include <stdio.h>
#include <math.h>

#include "vector.h"

// -------------
//  Vector Creation
// -------------

Vector
create_zero_vector(void)
{
    return create_vector3(0, 0, 0);
}

Vector
create_vector1(float x)
{
    Vector new_vector;
    new_vector.x = x;
    new_vector.y = 0;
    new_vector.z = 0;
    return new_vector;
}

Vector
create_vector2(float x, float y)
{
    Vector new_vector;
    new_vector.x = x;
    new_vector.y = y;
    new_vector.z = 0;
    return new_vector;
}

Vector
create_vector3(float x, float y, float z)
{
    Vector new_vector;
    new_vector.x = x;
    new_vector.y = y;
    new_vector.z = z;
    return new_vector;
}

Vector
copy_vector(Vector vector)
{
    return create_vector3(vector.x, vector.y, vector.z);
}

// -------------
//  Vector Math
// -------------

Vector
add_vectors(Vector vector_a, Vector vector_b)
{
    float new_x = vector_a.x + vector_b.x;
    float new_y = vector_a.y + vector_b.y;
    float new_z = vector_a.z + vector_b.z;
    return create_vector3(new_x, new_y, new_z);
}

Vector
sub_vectors(Vector vector_a, Vector vector_b)
{
    float new_x = vector_a.x - vector_b.x;
    float new_y = vector_a.y - vector_b.y;
    float new_z = vector_a.z - vector_b.z;
    return create_vector3(new_x, new_y, new_z);
}


Vector
normalized_vector(Vector vector)
{
    Vector return_vector = create_zero_vector();
    float x = vector.x;
    float y = vector.y;
    float z = vector.z;
    
    float size = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return_vector.x = x / size;
    return_vector.y = y / size;
    return_vector.z = z / size;

    return return_vector;
}

Vector
cross_product(Vector vector_a, Vector vector_b)
{
    Vector return_vector = create_zero_vector();

    return_vector.x = vector_a.y * vector_b.z - vector_a.z * vector_b.y;
    return_vector.y = vector_a.z * vector_b.x - vector_a.x * vector_b.z;
    return_vector.z = vector_a.x * vector_b.y - vector_a.y * vector_b.x;

    return return_vector;
}

float
vector_size(Vector vector)
{
    float x = vector.x;
    float y = vector.y;
    float z = vector.z;

    float size = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return size;
}

float
dot_product(Vector vector_a, Vector vector_b)
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
print_vector(Vector vector)
{
    printf("Vector{x:%03f, y:%03f, z:%03f}\n", vector.x, vector.y, vector.z);
}
