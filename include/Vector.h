#pragma once

struct Vector_t {
    float x;
    float y;
    float z;
};

typedef struct Vector_t Vector;

// -------------
//  Vector Creation
// -------------

Vector create_zero_vector(void);
Vector create_vector1(float x);
Vector create_vector2(float x, float y);
Vector create_vector3(float x, float y, float z);
Vector copy_vector(Vector vector);

// -------------
//  Vector Math
// -------------

Vector add_vectors(Vector vector_a, Vector vector_b);
Vector sub_vectors(Vector vector_a, Vector vector_b);

Vector cross_product(Vector vector_a, Vector vector_b);
Vector normalized_vector(Vector vector);

float vector_size(Vector vector);
float dot_product(Vector vector_a, Vector vector_b);


// -------------
//  Vector Utility
// -------------

float get_vector_x(Vector vector);
float get_vector_y(Vector vector);
float get_vector_z(Vector vector);

void print_vector(Vector vector);
