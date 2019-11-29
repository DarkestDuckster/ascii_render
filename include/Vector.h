#pragma once

struct _vector {
    int x;
    int y;
    int z;
};

typedef struct _vector Vector;

typedef Vector *Vector_t;

// -------------
//  Vector Creation
// -------------

Vector_t create_zero_vector(void);
Vector_t create_new_vector(int x, int y, int z);

// -------------
//  Vector Math
// -------------

Vector_t create_cross_product(Vector_t vector_a, Vector_t vector_b);
void set_cross_product(Vector_t *vector_out, Vector_t vector_a, Vector_t vector_b);

float get_dot_product(Vector_t vector_a, Vector_t vector_b);


// -------------
//  Vector Utility
// -------------

void delete_vector(Vector_t vector);
void print_vector(Vector_t vector);
