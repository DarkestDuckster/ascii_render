#pragma once

typedef struct _pixel {
    float r, g, b;
    const char *form;
} Pixel;

typedef struct _screen {
    int width;
    int height;
    Pixel *pixels;
} Screen;

typedef Screen *Screen_t;

Screen_t create_new_screen(int width, int height);

void print_screen(Screen_t screen);



