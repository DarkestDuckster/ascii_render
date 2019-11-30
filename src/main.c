#include <unistd.h>
#include "Vector.h"
#include "Screen.h"
#include "Triangle.h"
#include "Scene.h"
#include "Rasterizer.h"

int main(void)
{
    Vector_t vector = create_new_vector(63, 34, 1);
    print_vector(vector);

    Vector_t a = create_new_vector(1, 2, 3);
    Vector_t b = create_new_vector(4, 5, 6);
    Vector_t cross = cross_product(a, b);
    print_vector(cross);

    Triangle_t triangle = create_new_triangle(40, 5, 15, 30, 45, 25);

    Screen_t screen = create_new_screen(80, 40);
    Scene_t scene = create_new_scene();
    add_triangle_to_scene(scene, triangle);

    render_scene_onto_screen(scene, screen);
    add_sceen_border(screen);

    print_screen(screen);

    for (int i = 0; i < 200; i++) {
        printf("\033[41A");
        rotate_triangle_y(triangle, 0.1 * i);
        usleep(50000);
        clean_screen(screen);

        render_scene_onto_screen(scene, screen);
        add_sceen_border(screen);

        print_screen(screen);
    }

    delete_vector(vector);
    delete_triangle(triangle);
    delete_vector(a); delete_vector(b); delete_vector(cross);
    delete_screen(screen);
    delete_scene(scene);

    return 0;
}
