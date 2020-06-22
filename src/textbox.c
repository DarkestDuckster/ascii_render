#include <stdlib.h>
#include <string.h>

#include "textbox.h"

typedef struct _textbox {
    Renderable_t render_base;
    Vector pos;
    Vector size;
    char *contained_string;
    int string_size;
} Textbox_t;

Textbox
create_textbox(Vector pos, Vector size)
{
    // Textbot_t *new_textbox = RENDERABLE_INIT(Textbox_t,
    //                                          render_textbox_on_screen,
    //                                          delete_textbox);
                                             
    Textbox_t *new_textbox = malloc(sizeof(Textbox_t));
    create_render_base((Renderable) new_textbox,
                       (RenderFunction_t) &render_textbox_on_screen,
                       (DeleteFunction_t) &delete_textbox);
    new_textbox->pos = pos;
    new_textbox->size = size;
    new_textbox->contained_string = NULL;
    new_textbox->string_size = 0;
    return new_textbox;
}

Renderable
textbox_as_renderable(Textbox textbox)
{
    return &textbox->render_base;
}

void
set_string(Textbox textbox, const char *string)
{
    int str_size = strlen(string);
    if (textbox->contained_string != NULL) free(textbox->contained_string);
    textbox->contained_string = malloc(sizeof(char) * str_size);
    textbox->string_size = str_size;
    memcpy(textbox->contained_string, string, str_size);
}

void
render_textbox_on_screen(Textbox textbox, Screen screen)
{
    int offset = textbox->pos.y * screen->width + textbox->pos.x;
    for (int i = 0; i < textbox->string_size; i++) {
        screen->pixels[i + offset].tex = textbox->contained_string[i];
    }
}

void
delete_textbox(Textbox textbox)
{
    if (textbox->contained_string != NULL) free(textbox->contained_string);
    free(textbox);
}
