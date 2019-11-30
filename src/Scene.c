#include "Scene.h"
#include "Vector.h"
#include <stdlib.h>

typedef int (*check_vector_function) (Vector_t, void*);

typedef struct _scene_object {
    check_vector_function check_function;
    void *object_vectorer;
    char material;

} SceneObject;

struct _scene_struct {
    int current_num_objects;
    SceneObject *current_objects;
};


Scene_t
create_new_scene(void)
{
    struct _scene_struct *new_scene = malloc(sizeof(*new_scene));
    new_scene->current_num_objects = 0;
    new_scene->current_objects = NULL;

    return new_scene;
}

void
resize_scene_objects(Scene_t scene, int new_size)
{

    scene->current_num_objects = new_size;
    scene->current_objects = realloc(scene->current_objects,
                                     new_size * sizeof(SceneObject));

}

SceneObject*
create_new_scene_object(Scene_t scene)
{
    resize_scene_objects(scene, scene->current_num_objects + 1);
    return scene->current_objects + (scene->current_num_objects - 1);

}

void
add_triangle_to_scene(Scene_t scene, Triangle_t triangle)
{
    SceneObject *new_object = create_new_scene_object(scene);

    new_object->check_function = (check_vector_function) is_vector_in_triangle;
    new_object->object_vectorer = triangle;
    new_object->material = 'T';

}

const char
get_vector_render(Scene_t scene, int x, int y)
{
    Vector_t vector = create_new_vector(x, y, 0);

    for (int i = 0; i < scene->current_num_objects; i++) {
        SceneObject object_i = scene->current_objects[i];
        if (object_i.check_function(vector, object_i.object_vectorer))
            return object_i.material;
    }

    delete_vector(vector);
    return ' ';
}

void
render_scene_onto_screen(Scene_t scene, Screen_t screen)
{

    int width = screen->width, height = screen->height;

    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            const char render_value = get_vector_render(scene, j, i);
            screen->pixels[i * width + j].texture = render_value;
        }
    }
}


void
delete_scene(Scene_t scene)
{
    if (scene->current_objects == NULL)
        free(scene->current_objects);
    free(scene);
}
