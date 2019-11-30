#include "Triangle.h"
#include <stdlib.h>
#include <math.h>

Triangle_t
create_new_triangle(int A_x, int A_y,
                    int B_x, int B_y,
                    int C_x, int C_y)
{

    Triangle *new_triangle = malloc(sizeof(Triangle));

    new_triangle->A = create_new_vector(A_x, A_y, 1);
    new_triangle->B = create_new_vector(B_x, B_y, 1);
    new_triangle->C = create_new_vector(C_x, C_y, 1);

    new_triangle->_A = create_new_vector(A_x, A_y, 1);
    new_triangle->_B = create_new_vector(B_x, B_y, 1);
    new_triangle->_C = create_new_vector(C_x, C_y, 1);

    return new_triangle;

}

void
vector_rotate_y(Vector_t vector, float rotation_amount)
{
    vector->x = vector->x * cos(rotation_amount) + vector->y * sin(rotation_amount);
    vector->z = vector->x * -sin(rotation_amount) + vector->y * cos(rotation_amount);
}

void
set_vector_rotate_y(Vector_t vector_out, Vector_t vector_in, float rotation_amount)
{
    vector_out->x = vector_in->x;
    vector_out->y = vector_in->y;
    vector_out->z = vector_in->z;
    vector_rotate_y(vector_out, rotation_amount);
}

void
rotate_triangle_y(Triangle_t triangle, float rotation_amount)
{
    vector_rotate_y(triangle->A, rotation_amount);
    vector_rotate_y(triangle->B, rotation_amount);
    vector_rotate_y(triangle->C, rotation_amount);
    set_vector_rotate_y(triangle->A, triangle->_A, rotation_amount);
    set_vector_rotate_y(triangle->B, triangle->_B, rotation_amount);
    set_vector_rotate_y(triangle->C, triangle->_C, rotation_amount);

}

int sign_2d_vector (Vector_t p1, Vector_t p2, Vector_t p3)
{
    return (p1->x - p3->x) * (p2->y - p3->y) - (p2->x - p3->x) * (p1->y - p3->y);
}

// SignedVolume(a,b,c,d) = (1/6)*dot(cross(b-a,c-a),d-a)
float signed_tetrahedron_volume(Vector_t p1, Vector_t p2, Vector_t p3, Vector_t p4)
{
    Vector_t p2_sub_p1 = sub_vectors(p2, p1);
    Vector_t p3_sub_p1 = sub_vectors(p3, p1);
    Vector_t cross = cross_product(p2_sub_p1, p3_sub_p1);
    Vector_t p4_sub_p1 = sub_vectors(p3, p1);

    float volume = dot_product(cross, p4_sub_p1) / 6;

    delete_vector(p2_sub_p1);
    delete_vector(p3_sub_p1);
    delete_vector(p4_sub_p1);
    delete_vector(cross);
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
    delete_vector(triangle->A);
    delete_vector(triangle->B);
    delete_vector(triangle->C);
    free(triangle);
}
