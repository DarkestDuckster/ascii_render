#pragma once

typedef struct _dynamic_array DynamicArray_t;
typedef DynamicArray_t *DynamicArray;

DynamicArray create_dynamic_array(void);

void darr_add_object_to_array(DynamicArray array, void *object);
void darr_remove_object_by_index(DynamicArray array, int index);
void *darr_get_object_by_index(DynamicArray array, int index);
int darr_get_array_size(DynamicArray array);
