#pragma once
#include "Triangle.h"
#include "Screen.h"


struct _scene_struct;
typedef struct _scene_struct *Scene_t;


Scene_t create_new_scene(void);

void add_triangle_to_scene(Scene_t scene, Triangle_t triangle);

void render_scene_onto_screen(Scene_t scene, Screen_t screen);
