#include "Triangle.h"
#include <stdlib.h>
#include <math.h>

Triangle_t
create_new_triangle(float A_x, float A_y, float A_z,
                    float B_x, float B_y, float B_z,
                    float C_x, float C_y, float C_z)
{
    Triangle *new_triangle = malloc(sizeof(Triangle));

    float center_x = (A_x + B_x + C_x) / 3.f;
    float center_y = (A_y + B_y + C_y) / 3.f;
    float center_z = (A_z + B_z + C_z) / 3.f;

    new_triangle->center = create_new_vector(center_x, center_y, center_z);

    new_triangle->A = create_new_vector(A_x, A_y, A_z);
    new_triangle->B = create_new_vector(B_x, B_y, B_z);
    new_triangle->C = create_new_vector(C_x, C_y, C_z);

    new_triangle->A_offset = sub_vectors(new_triangle->A, new_triangle->center);
    new_triangle->B_offset = sub_vectors(new_triangle->B, new_triangle->center);
    new_triangle->C_offset = sub_vectors(new_triangle->C, new_triangle->center);

    new_triangle->translation = create_zero_vector();
    new_triangle->rotation = create_zero_vector();
    new_triangle->scale = create_zero_vector();


    return new_triangle;

}

void
set_triangle_translation(Triangle_t triangle, Vector_t translation)
{
  triangle->translation = translation;
}

void
set_triangle_rotation(Triangle_t triangle, Vector_t rotation)
{
  triangle->rotation = rotation;
}

void
set_triangle_scale(Triangle_t triangle, Vector_t scale)
{
  triangle->scale = scale;
}


void
apply_triangle_rotation(Triangle_t triangle)
{
    Vector_t rotation = triangle->rotation;
    Vector_t center = triangle->center;
    triangle->A.x = cos(rotation.x) * triangle->A_offset.x + center.x;
    triangle->B.x = cos(rotation.x) * triangle->B_offset.x + center.x;
    triangle->C.x = cos(rotation.x) * triangle->C_offset.x + center.x;

    triangle->A.y = cos(rotation.y) * triangle->A_offset.y + center.y;
    triangle->B.y = cos(rotation.y) * triangle->B_offset.y + center.y;
    triangle->C.y = cos(rotation.y) * triangle->C_offset.y + center.y;
}


int sign_2d_vector (Vector_t p1, Vector_t p2, Vector_t p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

// SignedVolume(a,b,c,d) = (1/6)*dot(cross(b-a,c-a),d-a)
float signed_tetrahedron_volume(Vector_t p1, Vector_t p2, Vector_t p3, Vector_t p4)
{
    Vector_t p2_sub_p1 = sub_vectors(p2, p1);
    Vector_t p3_sub_p1 = sub_vectors(p3, p1);
    Vector_t cross = cross_product(p2_sub_p1, p3_sub_p1);
    Vector_t p4_sub_p1 = sub_vectors(p3, p1);

    float volume = dot_product(cross, p4_sub_p1) / 6;

    return volume;

}

int
does_line_intersect_triangle(Vector_t line, Triangle_t triangle)
{
    return 0;
}

int
is_vector_in_triangle(Vector_t vector, Triangle_t triangle)
{
    int d1, d2, d3;
    int has_neg, has_pos;

    d1 = sign_2d_vector(vector, triangle->A, triangle->B);
    d2 = sign_2d_vector(vector, triangle->B, triangle->C);
    d3 = sign_2d_vector(vector, triangle->C, triangle->A);
    
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}

void
delete_triangle(Triangle_t triangle)
{
    free(triangle);
}
