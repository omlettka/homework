#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    int n = atoi(*(argv+1));
    int m = atoi(*(argv+2));
    int t = atoi(*(argv+3));
    srand(time(NULL));
    int *p = malloc(sizeof(int)* n);
    for (int i = 0; i<n; i++){
        *(p+i) = (int) rand() % m;
        printf("%i ", *(p+i));
    }
    printf("\n");
    for (int i = 0; i<n; i++){
        if(*(p+i)<t){
            printf("%i ", p);
        }
    }
}