#include <stdio.h>
#include <math.h>


// объявляем структуру точки
typedef struct {
    float x;
    float y;
} Point;


// функция вычисления расстояния между двумя точками по теореме пифагора
float dist(Point a, Point b){
    return sqrtf(powf(a.x-b.x, 2.0)+powf(a.y-b.y, 2.0));
}

/*
функция, которая определяет, лежат ли 3 точки на одной прямой
функция подставляет координаты третьей точки в уравнение прямой 1 и 2 точек и проверяет истинность
если точки 1 и 2 совпадают, возвращает -1
*/
int IsOnLine(Point a, Point b, Point c){
    if (a.x == b.x && a.y == b.y){
        return -1;
    } else if ((c.x == a.x && a.x == b.x) || (c.y == a.y && a.y == b.y)){
        return 1;
    } else if ((c.x-a.x)/(b.x-a.x) == (c.y-a.y)/(b.y-a.y)){
        return 1;
    } else{
        return 0;
    }
}

// фунцкция вычисления площади треугольника по формуле герона
float area(Point a, Point b, Point c){
    float a1 = dist(a, b);
    float b1 = dist(b, c);
    float c1 = dist(a, c);

    float p = (a1 + b1 + c1) / 2;
    return sqrtf(p * (p - a1) * (p - b1) * (p - c1));
}



// функция, определяющая лежит ли точка внутри треугольника по формулам из интернета
int IsInTriangle(Point a, Point b, Point c, Point d){
    float a1 = (a.x - d.x) * (b.y - a.y) - (b.x - a.x) * (a.y - d.y);
    float b1 = (b.x - d.x) * (c.y - b.y) - (c.x - b.x) * (b.y - d.y);
    float c1 = (c.x - d.x) * (a.y - c.y) - (a.x - c.x) * (c.y - d.y);
    if (IsOnLine(a, b, c) != 0){
        return -2;
    } else if ((a1 == 0 && (b1 * c1 >= 0)) || 
               (b1 == 0 && (a1 * c1 >= 0)) || 
               (c1 == 0 && (a1 * b1 >= 0))) {
    return -1;
    } else if ((a1 > 0 && b1 > 0 && c1 > 0) || (a1 < 0 && b1 < 0 && c1 < 0)){
        return 1;
    } else {
        return 0;
    }
}


// ввод значений идет через аргументы в командной строке
int main(int argc, char *argv[]){
    Point a, b, c, d;
    a.x = atof(argv[1]);
    a.y = atof(argv[2]);
    b.x = atof(argv[3]);
    b.y = atof(argv[4]);
    c.x = atof(argv[5]);
    c.y = atof(argv[6]);
    d.x = atof(argv[7]);
    d.y = atof(argv[8]);
    printf("Dist between point 1 and point 2 is %f\n", dist(a, b));
    switch (IsOnLine(a, b, c))
    {
    case 1:
        printf("Point 3 is on line of points 1 and 2\n");
        break;
    case 0:
        printf("Point 3 isn't on line of points 1 and 2\n");
        printf("Area of the triangle is %f\n", area(a, b, c));
        break;
    default:
        printf("Points 1 and 2 are equal\n");
        break;
    }
    switch (IsInTriangle(a, b, c, d))
    {
    case 1:
        printf("Point 4 is in triangle of points 1, 2 and 3\n");
        break;
    case 0:
        printf("Point 4 is not in triangle of points 1, 2 and 3\n");
        break;
    case -1:
        printf("Point 4 is on the border of triangle\n");
        break;
    default:
        printf("Points 1, 2 and 3 not a triangle");
        break;
    }
}