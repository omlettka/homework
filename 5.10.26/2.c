#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int n = atoi(*(argv+1));
    int m = atoi(*(argv+2));
    int *p1 = malloc(sizeof(int)* (n+1));
    int *p2 = malloc(sizeof(int)* (m+1));
    for (int i = 0; i<=n; i++){
        scanf("%i", (p1+i));
    }
    for (int i = 0; i<=m; i++){
        scanf("%i", (p2+i));
    }
    int *res = calloc(n+m+1, sizeof(int));
    for (int i = 0; i<=n; i++){
        for (int j = 0; j<=m; j++){
            /*
            i   = 0....n
            n-i = n....0
            i+j     = 0....n+m
            m+n-i-j = n+m....0
            k = x+y = n-i + m-j
            t = m+n-k = i+j
            */
           *(res+i+j) += (*(p1+i))*(*(p2+j));
        }
    }
    for (int i = 0; i< n+m; i++){
        if (*(res+i) != 0){
            printf("%ix^%i + ", *(res+i), n+m-i);
        }
    }
    printf("%i", *(res+n+m));
}