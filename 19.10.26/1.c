#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFINE_CMP(type, name) \
    static int name(const void *a, const void *b) { \
        type x = *(const type*)a; \
        type y = *(const type*)b; \
        return (x > y) - (x < y); \
    }

DEFINE_CMP(int, cmp_int)
DEFINE_CMP(double, cmp_double)
DEFINE_CMP(float, cmp_float)




#define sort_integer(arr, memb) qsort((arr), (memb), sizeof(int), cmp_int)
#define sort_double(arr, memb)  qsort((arr), (memb), sizeof(double), cmp_double)
#define sort_float(arr, memb)   qsort((arr), (memb), sizeof(float), cmp_float)

void print_int(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void print_double(double *arr, size_t n) {
    for (size_t i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("\n");
}

void print_float(float *arr, size_t n) {
    for (size_t i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    srand(time(NULL));
    int s1 = rand() % 10+1;
    int *arr_int = malloc(sizeof(int) * s1);
    for (int i = 0; i < s1; i++){
        *(arr_int + i) = rand()  % 200 - 100;
    }
    printf("Int before: ");
    print_int(arr_int, s1);
    sort_integer(arr_int, s1);
    printf("Int after:  ");
    print_int(arr_int, s1);
    printf("\n");

    int s2 = rand() % 10+1;
    double *arr_double = malloc(sizeof(double) * s2);
    for (int i = 0; i < s2; i++){
        *(arr_double + i) = (double)rand() / (double)RAND_MAX * 200 - 100;
    }
    printf("Double before: ");
    print_double(arr_double, s2);
    sort_double(arr_double, s2);
    printf("Double after:  ");
    print_double(arr_double, s2);
    printf("\n");

    int s3 = rand() % 10+1;
    float *arr_float = malloc(sizeof(float) * s3);
    for (int i = 0; i < s3; i++){
        *(arr_float + i) = (float)rand() / (float)RAND_MAX * 200 - 100;
    }
    printf("Float before: ");
    print_float(arr_float, s3);
    sort_float(arr_float, s3);
    printf("Float after:  ");
    print_float(arr_float, s3);

    free(arr_int);
    free(arr_double);
    free(arr_float);

    return 0;
}
