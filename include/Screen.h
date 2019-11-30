#pragma once

typedef struct _pixel {
    float r, g, b;
    char texture;
} Pixel;

typedef struct _screen {
    int width;
    int height;
    Pixel *pixels;
} Screen;

typedef Screen *Screen_t;

Screen_t create_new_screen(int width, int height);


void clean_screen(Screen_t screen);
void delete_screen(Screen_t screen);
void print_screen(Screen_t screen);

