#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    int n = atoi(*(argv+1)); // размер массива, atoi переводит из строки в int
    int m = atoi(*(argv+2)); // модуль
    int t = atoi(*(argv+3)); 
    srand(time(NULL)); // зерно (seed) генерации случайных чисел
    int *p = malloc(sizeof(int)* n); // динамически выделяем память под массив случайных чисел
    for (int i = 0; i<n; i++){
        *(p+i) = (int) rand() % m; // заполняем массив случайными числами
        printf("%i ", *(p+i)); // выводим массив
    }
    printf("\n");
    for (int i = 0; i<n; i++){
        if(*(p+i)<t){
            printf("%i ", i); // выводим числа, меньшие t
        }
    }
}