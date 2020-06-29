#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>

#include "screen.h"
#include "box.h"
#include "region.h"
#include "border.h"
#include "renderable.h"
#include "selectable.h"
#include "textbox.h"
#include "rasterizer.h"
#include "square.h"
#include "dynamic_array.h"


/**
 * 
 * Struct Description, so we don't have to look for it all the time.
 * Found in sys/ttycom.h.
 *
 * struct winsize {
 *   unsigned short ws_row;     // rows in characters 
 *   unsigned short ws_col;     // columns in characters
 *   unsigned short ws_xpixel;  // horizontal size, pixels
 *   unsigned short ws_ypixel;  // vertical size, pixels
 * };
 *
 **/

void array_test(void);
void vector_test(void);
void render_test(void);

int main(void)
{
    array_test();
    return 0;
}

void
array_test(void)
{
    Screen screen = create_screen(20, 20);
    Screen screen2 = create_screen(20, 20);
    Screen screen3 = create_screen(20, 20);
    printf("%p\n", screen);
    printf("%p\n", screen2);

    DynamicArray array = create_dynamic_array();
    printf("%d\n", darr_get_array_size(array));

    darr_add_object_to_array(array, screen);
    printf("%d\n", darr_get_array_size(array));
    printf("%p\n", darr_get_object_by_index(array, 0));
    printf("%p\n", darr_get_object_by_index(array, 1));
    printf("%p\n", darr_get_object_by_index(array, 2));

    darr_add_object_to_array(array, screen2);
    printf("%d\n", darr_get_array_size(array));
    printf("%p\n", darr_get_object_by_index(array, 0));
    printf("%p\n", darr_get_object_by_index(array, 1));
    printf("%p\n", darr_get_object_by_index(array, 2));

    darr_add_object_to_array(array, screen3);
    printf("%d\n", darr_get_array_size(array));
    printf("%p\n", darr_get_object_by_index(array, 0));
    printf("%p\n", darr_get_object_by_index(array, 1));
    printf("%p\n", darr_get_object_by_index(array, 2));

    darr_remove_object_by_index(array, 0);
    printf("%d\n", darr_get_array_size(array));
    printf("%p\n", darr_get_object_by_index(array, 0));
    printf("%p\n", darr_get_object_by_index(array, 1));
    printf("%p\n", darr_get_object_by_index(array, 2));
    
}

void
vector_test(void)
{
    Screen screen = create_screen(120, 40);
    Region region = create_region((Vector) {0, 0, 0},
                                  (Vector) {120, 40, 0});
    Rasterizer rasterizer = create_rasterizer();
    Square square = create_square((Vector) {20, 20, 0},
                                  (Vector) {30, 30, 0});
    Renderable border = (Renderable) create_border();

    add_object_to_rasterizer(rasterizer, (Intersectable) square);

    add_renderable_to_region(region, (Renderable) rasterizer);
    add_renderable_to_region(region, (Renderable) border);
    print_screen(screen);
    render_unto_screen((Renderable) region, screen);
    print_screen(screen);

    delete_renderable((Renderable) region);
    delete_screen(screen);
}

void
render_test(void)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    Screen screen = create_screen(120, 40);

    Region region = create_region((Vector) {0, 0, 0},
                                  (Vector) {120, 40, 0});
    Region region2 = create_region((Vector) {20, 20, 0},
                                  (Vector) {40, 10, 0});
    Renderable border = (Renderable) create_border();
    Renderable border2 = (Renderable) create_border();

    add_renderable_to_region(region, (Renderable) border);
    add_renderable_to_region(region, (Renderable) region2);
    add_renderable_to_region(region2, (Renderable) border2);

    print_screen(screen);
    render_unto_screen((Renderable) region, screen);
    printf("Columns: %hu\n", w.ws_row);
    sleep(1);
    print_screen(screen);
    
    select_renderable((Selectable) border2);
    render_unto_screen((Renderable) region, screen);
    sleep(1);
    print_screen(screen);

    delete_renderable((Renderable) region);
    delete_screen(screen);
}
