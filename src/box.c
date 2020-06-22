#include <stdlib.h>

#include "box.h"
#include "renderable.h"

const char BOX_VAL = '#';

typedef struct _box {
    Renderable_t renderable;
    Vector pos;
    Vector size;
} Box_t;

Box
create_box(Vector pos, Vector size)
{
    Box_t *new_box = malloc(sizeof(Box_t));
    create_render_base((Renderable) new_box,
                       (RenderFunction_t) &render_box_on_screen,
                       (DeleteFunction_t) &delete_box);
    new_box->pos = pos;
    new_box->size = size;
    return new_box;
}

void
render_box_on_screen(Box box, Screen screen)
{
    int width = screen->width;
    int height = screen->height;
    int box_width = box->size.x;
    int box_height = box->size.y;
    Pixel *pixels = screen->pixels;

    for (int i = box->pos.x; i < width && i < box_width + box->pos.x; i++) {
        for (int j = box->pos.y; j < height && j < box_height + box->pos.y; j++) {
            pixels[j * width + i].tex = BOX_VAL;
        }
    }

}

void
delete_box(Box box)
{
    free(box);
}
