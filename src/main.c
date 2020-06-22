#include <unistd.h>
#include <stdio.h>

#include "screen.h"
#include "box.h"
#include "region.h"
#include "border.h"
#include "renderable.h"
#include "selectable.h"
#include "textbox.h"

int main(void)
{

    Screen screen = create_screen(120, 40);

    Region region = create_region((Vector) {0, 0},
                                  (Vector) {120, 40});
    Region region2 = create_region((Vector) {20, 20},
                                  (Vector) {40, 10});
    Renderable border = (Renderable) create_border();
    Renderable border2 = (Renderable) create_border();

    add_renderable_to_region(region, (Renderable) border);
    add_renderable_to_region(region, (Renderable) region2);
    add_renderable_to_region(region2, (Renderable) border2);

    print_screen(screen);
    render_unto_screen((Renderable) region, screen);
    sleep(1);
    print_screen(screen);
    
    select_renderable((Selectable) border2);
    render_unto_screen((Renderable) region, screen);
    sleep(1);
    print_screen(screen);

    delete_renderable((Renderable) region);
    delete_screen(screen);
    return 0;
}
