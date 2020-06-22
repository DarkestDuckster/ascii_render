#pragma once
#include "vector.h"

typedef struct _circle Circle_t;
typedef Circle_t *Circle;


Circle create_circle(Vector center, Vector radius);

void delete_circle(Circle circle);
