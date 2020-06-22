#include "screen.h"
#include <stdio.h>
#include <stdlib.h>

const char CLEAR_CHAR = ' ';

Screen
create_screen(int width, int height)
{
    Screen_t *new_screen = malloc(sizeof(Screen_t));
    new_screen->width = width;
    new_screen->height = height;

    int num_pixels = width * height;
    new_screen->pixels = malloc(sizeof(*new_screen->pixels) * num_pixels);
    for (int i = 0; i < num_pixels; i++) {
        new_screen->pixels[i].tex = CLEAR_CHAR;
    }

    return new_screen;
}

void
clean_screen(Screen screen)
{
    int width = screen->width;
    int height = screen->height;

    int num_pixels = width * height;
    for (int i = 0; i < num_pixels; i++)
        screen->pixels[i].tex = CLEAR_CHAR;
}

void
delete_screen(Screen screen)
{
    free(screen->pixels);
    free(screen);
}

void
print_screen(Screen screen)
{
    int width = screen->width;
    int height = screen->height;

    printf("\033[50A");
    #ifdef DEBUG_FRAME
    printf("\033[0K");
    printf("Screen Info: Width=%02d , Height=%02d\n",
           width, height);

    printf("\033[0K");
    printf("      ");
    for (int i = 0; i < width; i++) {
        if (i % 10 == 0) printf("%1d", (int) i / 10 % 10);
        else printf("*");
    }
    printf("\n");

    printf("\033[0K");
    printf("    /-");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("-\\\n");
    #endif

    for (int i = 0; i < height; i++) {
        printf("\033[0K");
        #ifdef DEBUG_FRAME
        printf("%02d: | ", i+1);
        #endif
        for (int j = 0; j < width; j++) {
            printf("%c", screen->pixels[i * width + j].tex); 
        }
        #ifdef DEBUG_FRAME
        printf(" |");
        #endif
        printf("\n");
    }

    #ifdef DEBUG_FRAME
    printf("\033[0K");
    printf("    \\-");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("-/\n");
    #endif
}
