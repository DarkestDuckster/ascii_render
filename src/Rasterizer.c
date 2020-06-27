#include <stdlib.h>

#include "rasterizer.h"

typedef struct _rasterizer {
    RENDER_BASE;
    int num_objects;
    int object_arr_size;
    void **objects;
} Rasterizer_t;

DECLARE_RENDER_FUNCTIONS(RASTERIZER, render_rasterizer_on_screen, delete_rasterizer);

Rasterizer
create_rasterizer(void)
{
    Rasterizer_t *new_rasterizer = malloc(sizeof(Rasterizer_t));
    INIT_RENDER_BASE(RASTERIZER, new_rasterizer);
    new_rasterizer->num_objects = 0;
    new_rasterizer->object_arr_size = 0;
    new_rasterizer->objects = NULL;
    return new_rasterizer;
}

void
add_object_to_rasterizer(Rasterizer rasterizer, Intersectable intersectable)
{
    if (rasterizer->object_arr_size == 0) {
        rasterizer->object_arr_size = 1;
        rasterizer->objects = malloc(sizeof(*(rasterizer->objects)));
    }

    if (rasterizer->num_objects >= rasterizer->object_arr_size) {
        rasterizer->object_arr_size = rasterizer->object_arr_size * 2;
        rasterizer->objects = realloc(rasterizer->objects,
                                      sizeof(*(rasterizer->objects)) * rasterizer->object_arr_size);
    }

    rasterizer->objects[rasterizer->num_objects] = (void*) intersectable;
    rasterizer->num_objects += 1;
}

void
render_rasterizer_on_screen(Rasterizer rasterizer, Screen screen)
{
    int width = get_screen_width(screen);
    int height = get_screen_height(screen);
    int num_objects = rasterizer->num_objects;
    void **objects = rasterizer->objects;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Vector origin = {x, y, 1};
            Vector direction = {0, 0, -1};
            for (int i = 0; i < num_objects; i++) {
                if (get_intersection(objects[i], origin, direction))
                    set_screen_pixel(screen, x, y, '*');
            }
        }
    }
}

void
delete_rasterizer(Rasterizer rasterizer)
{
    if (rasterizer->objects != NULL) free(rasterizer->objects);
    free(rasterizer);    
}
