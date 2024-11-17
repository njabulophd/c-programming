#define NN_IMPLEMENTATION
#include "./stb/nn.h"

int main()
{
    //srand(time(NULL));
    Mat mymat = mat_alloc(3,2);
    Mat othermat = mat_alloc(2,1);
    print_mat(mymat);
    printf("_____________________________________________________________\n");
    mat_fill(mymat, 1);
    mat_fill(othermat, 1);
    Mat other = mat_dot(mymat, othermat);
    print_mat(other);
    return 0;
}