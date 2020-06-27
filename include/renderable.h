#pragma once

#include "screen.h"

typedef void (*RenderFunction_t) (void *, Screen);
typedef void (*DeleteFunction_t) (void *);

typedef struct _renderable {
    RenderFunction_t render_function;
    DeleteFunction_t delete_function;
} Renderable_t;
typedef Renderable_t *Renderable;

#define RENDER_BASE \
struct { \
    Renderable render_base; \
}

/**
 *
 * name##_RENDER_BASE is the shared object which contains the function pointers that
 * all implement the renderable functionality. Each inheriting structure contains its
 * own function pointer structure, which is shared by all of the same structure.
 *
 **/

#define DECLARE_RENDER_FUNCTIONS(name, child_render_function, child_delete_function) \
Renderable_t name##_RENDER_BASE = {(RenderFunction_t) child_render_function, \
                                    (DeleteFunction_t) child_delete_function};

#define INIT_RENDER_BASE(name, new_object) \
new_object->render_base = &name##_RENDER_BASE;

#define GET_RENDERABLE(object) \
((RENDER_BASE*) object)->render_base

void render_unto_screen(Renderable object_to_render, Screen screen_to_render_on);

void delete_renderable(Renderable renderable);
