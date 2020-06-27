#pragma once

#include "renderable.h"

typedef void (*SelectFunction_t) (void *);
typedef void (*DeselectFunction_t) (void *);

typedef struct _selectable_functions {
    SelectFunction_t select_function;
    DeselectFunction_t deselect_function;
} Selectable_f;

typedef struct _selectable_vars {
    int selected;
} Selectable_v;

typedef struct _selectable {
    Selectable_f *function_base;
    Selectable_v variables;
} Selectable_t;
typedef Selectable_t *Selectable;

#define SELECTABLE_BASE \
struct { \
    RENDER_BASE; \
    Selectable selectable_base; \
}

#define DECLARE_SELECTABLE_FUNCTIONS(name, \
                                     child_render_function, \
                                     child_delete_function, \
                                     child_select_function, \
                                     child_deselect_function) \
DECLARE_RENDER_FUNCTIONS(name, child_render_function, child_delete_function) \
Selectable_f name##_SELECT_BASE = {(SelectFunction_t) child_select_function, \
                                   (DeselectFunction_t) child_deselect_function};

#define INIT_SELECT_BASE(name, new_object) \
INIT_RENDER_BASE(name, new_object) \
new_object->selectable_base = malloc(sizeof(Selectable_t)); \
new_object->selectable_base->function_base = &name##_SELECT_BASE; \
new_object->selectable_base->variables.selected = 0;

#define GET_SELECTABLE(object) \
((SELECTABLE_BASE*) object)->selectable_base


int get_selected(Selectable selectable);
void select_renderable(Selectable selectable);
void delete_selectable(Selectable selectable);
