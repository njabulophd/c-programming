#define NN_IMPLEMENTATION
#include "./stb/nn.h"

int main()
{
    srand(time(NULL));
    Mat mymat = mat_alloc(4,4);
    mat_rand(mymat, 1.f, 20.0f);
    print_mat(mymat);
    return 0;
}