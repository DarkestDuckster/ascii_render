#include "Vector.h"
#include "Screen.h"
#include "Triangle.h"
#include "Scene.h"
#include "Rasterizer.h"

int main(void)
{
    Vector_t vector = create_new_vector(63, 34, 1);
    print_vector(vector);

    Triangle_t triangle = create_new_triangle(40, 5, 35, 10, 45, 15);

    Screen_t screen = create_new_screen(80, 40);

    Scene_t scene = create_new_scene();

    add_triangle_to_scene(scene, triangle);
    render_scene_onto_screen(scene, screen);

    add_sceen_border(screen, "\xE2\x98\x85");

    print_screen(screen);

    return 0;
}
