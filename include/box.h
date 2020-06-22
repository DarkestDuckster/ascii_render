#pragma once

#include "screen.h"
#include "vector.h"
#include "renderable.h"

typedef struct _box Box_t;
typedef Box_t *Box;

Box create_box(Vector pos, Vector size);
Renderable create_box_renderable(Vector pos, Vector size);
Renderable box_as_renderable(Box box);

void render_box_on_screen(Box box, Screen screen);

void delete_box(Box box);
