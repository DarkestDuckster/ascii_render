#pragma once

typedef struct _pixel {
    char tex;
} Pixel;

typedef struct _screen {
    int width;
    int height;
    Pixel *pixels;
} Screen_t;

typedef Screen_t *Screen;

Screen create_screen(int width, int height);

void clean_screen(Screen screen);
void delete_screen(Screen screen);

void print_screen(Screen screen);
