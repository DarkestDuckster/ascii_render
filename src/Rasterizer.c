#include <stdlib.h>

#include "rasterizer.h"

typedef struct _rasterizer {
    RENDER_BASE;
    int num_objects;
    int object_arr_size;
    void **objects;
} Rasterizer_t;

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
    
}

void
delete_rasterizer(Rasterizer rasterizer)
{

}
