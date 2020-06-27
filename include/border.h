#pragma once

#include "screen.h"
#include "selectable.h"

typedef struct _border Border_t;
typedef Border_t *Border;

Border create_border(void);
Renderable border_as_renderable(Border border);

void render_border_on_screen(Border border, Screen screen);
void delete_border(Border border);

