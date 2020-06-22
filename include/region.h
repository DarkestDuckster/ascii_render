#pragma once

#include "screen.h"
#include "vector.h"
#include "renderable.h"

typedef struct _region Region_t;
typedef Region_t *Region;

Region create_region(Vector pos, Vector size);
Renderable region_as_renderable(Region region);

void add_renderable_to_region(Region region, Renderable renderable);
void translate_region(Region region, Vector translation);
