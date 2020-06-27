#include <stdio.h>
#include <stdlib.h>

#include "border.h"

typedef struct _border {
    SELECTABLE_BASE;
    char horizontal_border;
    char vertical_border;
    char selected_border;
} Border_t;

DECLARE_SELECTABLE_FUNCTIONS(BORDER, render_border_on_screen, delete_border, NULL, NULL);

Border create_border(void)
{
    Border_t *new_border = malloc(sizeof(Border_t));
    INIT_SELECT_BASE(BORDER, new_border);
    new_border->horizontal_border = '-';
    new_border->vertical_border = '|';
    new_border->selected_border = '#';
    return new_border;
}


void
render_border_on_screen(Border border, Screen screen)
{    
    int width = get_screen_width(screen);
    int height = get_screen_height(screen);

    int selected = get_selected((Selectable) border);
    char horizontal_border, vertical_border;
    if (selected) {
        horizontal_border = border->selected_border;
        vertical_border = border->selected_border;
    }
    else {
        horizontal_border = border->horizontal_border;
        vertical_border = border->vertical_border;
    }
    
    for (int i = 0; i < width; i++) {
        set_screen_pixel(screen, i, 0, horizontal_border);
        set_screen_pixel(screen, i, height - 1, horizontal_border);
    }
    for (int i = 0; i < height; i++) {
        set_screen_pixel(screen, 0, i, vertical_border);
        set_screen_pixel(screen, width - 1, i, vertical_border);
    }

    char corner = '#';
    set_screen_pixel(screen, 0, 0, corner);
    set_screen_pixel(screen, width - 1, 0, corner);
    set_screen_pixel(screen, 0, height - 1, corner);
    set_screen_pixel(screen, width - 1, height - 1, corner);
}

void
delete_border(Border border)
{
    delete_selectable((Selectable) border);
    free(border);
}
