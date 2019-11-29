#include "Screen.h"
#include <stdio.h>
#include <stdlib.h>

Screen_t
create_new_screen(int width, int height)
{
    Screen *new_screen = malloc(sizeof(Screen));
    new_screen->width = width;
    new_screen->height = height;

    int num_pixels = width * height;
    new_screen->pixels = malloc(sizeof(*new_screen->pixels) * num_pixels);
    for (int i = 0; i < num_pixels; i++) {
        new_screen->pixels[i].r = 0;
        new_screen->pixels[i].g = 0;
        new_screen->pixels[i].b = 0;
        new_screen->pixels[i].form = " ";
    }

    return new_screen;
}

void
print_screen(Screen_t screen)
{
    int width = screen->width;
    int height = screen->height;

    printf("Screen Info: Width=%02d , Height=%02d\n",
           width, height);

    for (int i = 0; i < height; i++) {
        printf("%02d: | ", i+1);
        for (int j = 0; j < width; j++) {
            printf("%s", screen->pixels[i * width + j].form); 
        }
        printf("\n");
    }
}
