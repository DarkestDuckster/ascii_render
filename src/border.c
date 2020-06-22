#include <stdio.h>
#include <stdlib.h>

#include "border.h"

typedef struct _border {
    SELECTABLE_BASE;
    char horizontal_border;
    char vertical_border;
    char selected_border;
} Border_t;

void render_border_on_screen(Border border, Screen screen);
void delete_border(Border border);

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
    int width = screen->width;
    int height = screen->height;
    Pixel *pixels = screen->pixels;

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
        pixels[i].tex = horizontal_border;
        pixels[(height - 1) * width + i].tex = horizontal_border;
    }
    for (int i = 0; i < height; i++) {
        pixels[i * width].tex = vertical_border;
        pixels[i * width + width - 1].tex = vertical_border;
    }
    pixels[0].tex = '#';
    pixels[width - 1].tex = '#';
    pixels[(height - 1) * width].tex = '#';
    pixels[(height - 1) * width + width - 1].tex = '#';
}

void
delete_border(Border border)
{
    free(border);
}
