#pragma once

#include "vector.h"

typedef int (*IntersectFunction_t) (void *object, Vector origin, Vector direction);

typedef struct _intersect_functions {
    IntersectFunction_t intersect_function;
} Intersectable_f;

typedef struct _intersectable Intersectable_t;
typedef Intersectable_t *Intersectable;

Intersectable init_intersectable(Intersectable_f *function_struct);

int get_intersection(Intersectable intersectable, Vector origin, Vector direction);
void add_child_intersectable(Intersectable intersectable, Intersectable new_child);
void delete_intersectable(Intersectable intersectable);

void rotate(Intersectable intersectable, Vector rotation);
