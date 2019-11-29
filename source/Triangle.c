#include "Triangle.h"
#include <stdlib.h>

Triangle_t
create_new_triangle(int A_x, int A_y,
                    int B_x, int B_y,
                    int C_x, int C_y)
{

    Triangle *new_triangle = malloc(sizeof(Triangle));

    new_triangle->A = create_new_vector(A_x, A_y, 1);
    new_triangle->B = create_new_vector(B_x, B_y, 1);
    new_triangle->C = create_new_vector(C_x, C_y, 1);

    return new_triangle;

}

int sign_2d_vector (Vector_t p1, Vector_t p2, Vector_t p3)
{
    return (p1->x - p3->x) * (p2->y - p3->y) - (p2->x - p3->x) * (p1->y - p3->y);
}

//int signed_tetrahedron_volume(Vector_t p1, Vector_t p2, Vector_t p3, Vector_t p4)
//{
//
//    SignedVolume(a,b,c,d) = (1/6)*dot(cross(b-a,c-a),d-a)
//
//}


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
