#pragma once

#include "vector.h"
#include "screen.h"
#include "renderable.h"
#include "intersectable.h"

typedef struct _rasterizer Rasterizer_t;
typedef Rasterizer_t *Rasterizer;

Rasterizer create_rasterizer(void);

void add_object_to_rasterizer(Rasterizer rasterizer, Intersectable intersectable);

void render_rasterizer_on_screen(Rasterizer rasterizer, Screen screen);
void delete_rasterizer(Rasterizer rasterizer);
