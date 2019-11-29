#pragma once

struct _vector {
    float x;
    float y;
    float z;
};

typedef struct _vector Vector;

typedef Vector *Vector_t;

// -------------
//  Vector Creation
// -------------

Vector_t create_zero_vector(void);
Vector_t create_new_vector(float x, float y, float z);

// -------------
//  Vector Math
// -------------

Vector_t add_vectors(Vector_t vector_a, Vector_t vector_b);
Vector_t sub_vectors(Vector_t vector_a, Vector_t vector_b);

Vector_t cross_product(Vector_t vector_a, Vector_t vector_b);

float dot_product(Vector_t vector_a, Vector_t vector_b);


// -------------
//  Vector Utility
// -------------

void delete_vector(Vector_t vector);
void print_vector(Vector_t vector);
