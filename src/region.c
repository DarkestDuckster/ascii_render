#include <stdlib.h>

#include "region.h"

typedef struct _region {
    RENDER_BASE;
    Renderable *contained_objects;
    int num_of_renderables;
    Vector pos;
    Vector size;
} Region_t;


DECLARE_RENDER_FUNCTIONS(REGION, render_region_on_screen, delete_region);

Region
create_region(Vector pos, Vector size)
{
    Region_t *new_region = malloc(sizeof(Region_t));
    INIT_RENDER_BASE(REGION, new_region);
    new_region->pos = pos;
    new_region->size = size;
    new_region->num_of_renderables = 0;
    new_region->contained_objects = NULL;
    return new_region;
}

void
add_renderable_to_region(Region region, Renderable renderable)
{
    region->num_of_renderables += 1;
    region->contained_objects = realloc(region->contained_objects, sizeof(Renderable) * region->num_of_renderables);
    region->contained_objects[region->num_of_renderables - 1] = renderable;
}

void
translate_region(Region region, Vector translation)
{
    region->pos.x += translation.x;
    region->pos.y += translation.y;
}

void
render_region_on_screen(Region region, Screen screen)
{
    Screen temp_screen = create_screen(region->size.x, region->size.y);

    for (int i = 0; i < region->num_of_renderables; i++) {
        render_unto_screen(region->contained_objects[i], temp_screen);
    }

    int scwidth = get_screen_width(screen);
    int scheight = get_screen_height(screen);

    for (int i = 0; i < region->size.x && i + region->pos.x < scwidth; i++) {
        for (int j = 0; j < region->size.y && j + region->pos.y < scheight; j++) {

            char pix = get_screen_pixel(temp_screen, i, j);
            set_screen_pixel(screen,
                             i + region->pos.x,
                             j + region->pos.y,
                             pix);
        }
    }

    delete_screen(temp_screen);
}

void
delete_region(Region region)
{
    for (int i = 0; i < region->num_of_renderables; i++) {
        delete_renderable(region->contained_objects[i]);
    }
    if (region->contained_objects != NULL) free(region->contained_objects);
    free(region);
}
