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

#define DECLARE_INTERSECT_FUNCTIONS(name, child_intersect_function) \
Intersectable_t name##_INTERSECT_BASE = {(IntersectFunction_t) child_intersect_function}

#define INIT_INTERSECT_BASE(name, new_object) \
new_object->intersect_base = malloc(sizeof(Intersectable_t)); \
new_object->intersect_base->function_base = &name##_INTERSECT_BASE; \
new_object->intersect_base->variables.num_children = 0; \
new_object->intersect_base->variables.children_size = 0; \
new_object->intersect_base->variables.children = NULL;

#define INTERSECT_BASE_STRUCT \
struct { \
    INTERSECT_BASE \
}

#define GET_INTERSECTABLE(object) \
((INTERSECT_BASE*) object)->intersect_base

int get_intersection(Intersectable intersectable, Vector origin, Vector direction);
void add_child_intersectable(Intersectable intersectable, Intersectable new_child);
void delete_intersectable(Intersectable intersectable);
