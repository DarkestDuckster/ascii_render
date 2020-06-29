#include <stdlib.h>

#include "dynamic_array.h"

typedef struct _dynamic_array {
    int size;
    int pointer_size;
    void **objects;
} DynamicArray_t;

DynamicArray
create_dynamic_array(void)
{
    DynamicArray_t *new_array = malloc(sizeof(DynamicArray_t));
    new_array->size = 0;
    new_array->pointer_size = 0;
    new_array->objects = NULL;
    return new_array;
}

void
darr_add_object_to_array(DynamicArray array, void *object)
{
    if (object == NULL) return;

    if (array->pointer_size == 0) {
        array->pointer_size = 1;
        array->objects = malloc(sizeof(*(array->objects)) * array->pointer_size);
    }

    if (array->size == array->pointer_size) {
        array->pointer_size *= 2;
        array->objects = realloc(array->objects, sizeof(*(array->objects)) * array->pointer_size);
    }

    array->objects[array->size] = object;
    array->size += 1;
}

void
darr_remove_object_by_index(DynamicArray array, int index)
{
    if (index >= array->pointer_size) return;
    if (array->objects[index] == NULL) return;

    array->objects[index] = NULL;
    array->size -= 1;

    for (int i = index; i < array->pointer_size; i++) {
        array->objects[i] = array->objects[i+1];
    }

    if (array->size == 0) {
        array->pointer_size = 0;
        free(array->objects);
    }

    if (array->size == array->pointer_size / 2) {
        array->objects = realloc(array->objects, sizeof(*(array->objects)) * array->size);
        array->pointer_size = array->size;
    }

}

void *
darr_get_object_by_index(DynamicArray array, int index)
{
    if (index >= array->pointer_size) {
        return NULL;
    }
    return array->objects[index];
}

int
darr_get_array_size(DynamicArray array)
{
    return array->size;
}
