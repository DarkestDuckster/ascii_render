#pragma once

typedef struct _screen Screen_t;
typedef Screen_t *Screen;

Screen create_screen(int width, int height);

void clean_screen(Screen screen);
void delete_screen(Screen screen);

int get_screen_width(Screen screen);
int get_screen_height(Screen screen);
void set_screen_pixel(Screen screen, int x, int y, char pixel_value);
char get_screen_pixel(Screen screen, int x, int y);

void print_screen(Screen screen);
