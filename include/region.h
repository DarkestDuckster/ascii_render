#pragma once

#include "screen.h"
#include "vector.h"
#include "renderable.h"

typedef struct _region Region_t;
typedef Region_t *Region;

Region create_region(Vector pos, Vector size);

void add_renderable_to_region(Region region, Renderable renderable);
void translate_region(Region region, Vector translation);

void render_region_on_screen(Region region, Screen screen);
void delete_region(Region region);

