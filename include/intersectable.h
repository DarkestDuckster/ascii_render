#pragma once

#include "vector.h"

typedef int (*IntersectFunction_t) (void *object, Vector origin, Vector direction);

typedef struct _intersect_functions {
    IntersectFunction_t intersect_function;
} Intersectable_f;

typedef struct _intersect_vars {
    int num_children;
    int children_size;
    void **children;
} Intersectable_v;

typedef struct _intersectable {
    Intersectable_f *function_base;
    Intersectable_v variables;
} Intersectable_t;
typedef Intersectable_t *Intersectable;

#define INTERSECT_BASE \
struct { \
    Intersectable intersect_base; \
}

#define GET_INTERSECTABLE(object) \
((INTERSECT_BASE*) object)->intersect_base

Intersectable init_intersectable(Intersectable_f *function_struct);

int get_intersection(Intersectable intersectable, Vector origin, Vector direction);
void add_child_intersectable(Intersectable intersectable, Intersectable new_child);
void delete_intersectable(Intersectable intersectable);
