#include <stdlib.h>

#include "intersectable.h"

IntersectFunction_t
get_intersect_function(Intersectable intersectable)
{
    return intersectable->function_base->intersect_function;
}

Intersectable_v *
get_intersect_variables(Intersectable intersectable)
{
    return &intersectable->variables;
}

Intersectable
init_intersectable(Intersectable_f *function_struct)
{
    Intersectable_t *new_intersectable = malloc(sizeof(Intersectable_t));
    new_intersectable->function_base = function_struct;
    new_intersectable->variables.num_children = 0;
    new_intersectable->variables.children_size = 0;
    new_intersectable->variables.children = 0;
    return new_intersectable;
}

void
add_child_intersectable(Intersectable intersectable, Intersectable new_child)
{
    Intersectable base = GET_INTERSECTABLE(intersectable);
    Intersectable_v *variables = get_intersect_variables(base);

    if (variables->children_size == 0) {
        variables->children_size = 1;
        variables->children = malloc(sizeof(*(variables->children)) * variables->children_size);
    }
    
    if (variables->num_children >= variables->children_size) {
        variables->children_size = variables->children_size * 2;
        variables->children = realloc(variables->children,
                                      sizeof(*(variables->children)) * variables->children_size);
    }

    variables->children[variables->num_children] = (void*) new_child;
    variables->num_children += 1;
}

int
get_intersection(Intersectable intersectable, Vector origin, Vector direction)
{
    int intersection = 0;

    Intersectable base = GET_INTERSECTABLE(intersectable);

    // First check the object itself.
    IntersectFunction_t intersect_function = get_intersect_function(base);
    if (intersect_function != NULL) {
        intersection = intersect_function(intersectable, origin, direction);
        if (intersection != 0) return intersection;
    }

    // Try if any children intersect.
    Intersectable_v *variables = get_intersect_variables(base);
    for (int i = 0; i < variables->num_children; i++) {
        intersection = get_intersection((Intersectable) variables->children[i], origin, direction);
        if (intersection != 0) return intersection;
    }

    return intersection; 
}

void
delete_intersectable(Intersectable intersectable)
{
    Intersectable base = GET_INTERSECTABLE(intersectable);
    Intersectable_v *variables = get_intersect_variables(base);
    variables->children_size = 0;
    variables->num_children = 0;
    free(variables->children);
    variables->children = NULL;
    free(base);
}
