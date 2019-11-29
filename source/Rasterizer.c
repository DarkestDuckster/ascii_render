#include "Rasterizer.h"

const char *POINT_CHAR = "#";
const char *TRIANGLE_CHAR = "T";

void
add_vector_to_screen(Screen_t screen, Vector_t vector)
{
    int vector_x = vector->x, vector_y = vector->y;
    int width = screen->width, height = screen->height;

    Pixel *screen_pixels = screen->pixels;
    screen_pixels[vector_y * width + vector_x].form = POINT_CHAR;
}

void
add_triangle_to_screen(Screen_t screen, Triangle_t triangle)
{

    Vector_t vector = create_new_vector(0, 0, 0);
    int width = screen->width, height = screen->height;

    Pixel *screen_pixels = screen->pixels;
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

            vector->x = i; vector->y = j;
            if (is_vector_in_triangle(vector, triangle))
                screen_pixels[j * width + i].form = TRIANGLE_CHAR;

        }
    }
    delete_vector(vector);
}

void
add_sceen_border(Screen_t screen, const char *form)
{
    int width = screen->width;
    int height = screen->height;

    Pixel *screen_array = screen->pixels;

    for (int i = 0; i < width; i++) {
        screen_array[i].form = form;
        screen_array[(height - 1) * width + i].form = form;
    }
    for (int i = 1; i < height-1; i++) {
        screen_array[i * width].form = form;
        screen_array[i * width + width-1].form = form;
    }
}
