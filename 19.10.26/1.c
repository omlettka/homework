#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define sort_integer(int *arr, size_t memb) qsort(*arr, memb)
#define sort_double(double *arr, size_t memb) qsort(*arr, memb)

#define print_int_arr(int *arr, int size) for (int i = 0; i < size; i++) {printf("%i ", *(arr+i));} printf("\n");
#define print_double_arr(double *arr, int size) for (int i = 0; i < size; i++) {printf("%d ", *(arr+i));} printf("\n");

int main(){
    srand(time(NULL));
    int s1 = rand() % 10;
    int *arr_int = malloc(sizeof(int) * s1);
    for (int i = 0; i < s1; i++){
        *(arr_int + i) = rand()  % 200 - 100;
    }
    int s2 = rand() % 10;
    double *arr_double = malloc(sizeof(double) * s2);
    for (int i = 0; i < s2; i++){
        *(arr_double + i) = (double)rand() / (double)RAND_MAX * 200 - 100;
    }
    print_int_arr(arr_int, s1)
    print_int_arr(*sort_integer(arr_int), s1)
    print_double_arr(arr_double, s2)
    print_double_arr(*sort_double(arr_double), s2)

}