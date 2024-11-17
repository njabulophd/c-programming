#ifndef NN_H
#define NN_H

#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#ifndef NN_MALLOC
#include <stdlib.h>
#define NN_MALLOC malloc
#endif //NN_MALLOC

#ifndef NN_ASSERT
#include <assert.h>
#define NN_ASSERT assert
#endif //NN_ASSERT

#define MAT_AT(m,i,j) (m).es[(i)*(m).cols+(j)]

typedef struct{
    size_t rows;
    size_t cols;
    float *es;
}Mat;

Mat mat_alloc(size_t rows, size_t cols);
void mat_dot(Mat dest, Mat a);
void mat_sum(Mat dest, Mat a);
void print_mat(Mat m);
void mat_rand(Mat m, float low, float high);
float rand_float(void);
#endif //NN_H

#ifdef NN_IMPLEMENTATION
float rand_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}
Mat mat_alloc(size_t rows, size_t cols)
{
    Mat m;
    m.rows = rows;
    m.cols = cols;
    m.es = NN_MALLOC(sizeof(*m.es)*rows*cols);
    NN_ASSERT(m.es != NULL);
    return m;
}
void mat_dot(Mat dest, Mat a)
{
    (void)dest;
    (void)a; 
}
void mat_sum(Mat dest, Mat a)
{
    (void)dest;
    (void)a;
}
void print_mat(Mat m)
{
    for(size_t i = 0; i < m.rows; ++i)
    {
        for(size_t j = 0; j < m.cols; ++j)
        {
            printf("%f\t", MAT_AT(m, i,j));
        }
        printf("\n");
    }
}
void mat_rand(Mat m, float low, float high)
{
    for(size_t i = 0; i < m.rows; ++i)
    {
        for(size_t j = 0; j < m.cols; ++j)
        {
       //      MAT_AT(m, i,j) = ceil(rand_float() * 10);
            MAT_AT(m, i,j) = rand_float() * (high - low) + low;
        }
    }
}
#endif