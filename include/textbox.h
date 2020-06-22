#pragma once

#include "screen.h"
#include "vector.h"
#include "renderable.h"

typedef struct _textbox Textbox_t;
typedef Textbox_t *Textbox;

Textbox create_textbox(Vector pos, Vector size);
Renderable textbox_as_renderable(Textbox textbox);

void render_textbox_on_screen(Textbox textbox, Screen screen);
void set_string(Textbox textbox, const char *string);

void delete_textbox(Textbox textbox);
