#include <stdio.h>
#include <math.h>
#define PIE 3.141592653589793
typedef struct Point_s
{
    double x;
    double y;
}Point;

double calculateAngle(Point a, Point b, Point c) 
{
    Point ab;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    Point bc;
    bc.x = b.x - c.x;
    bc.y = b.y - c.y;

    double vector = ab.x * bc.x + ab.y * bc.y;

    double scalAB = sqrt(ab.x * ab.x + ab.y * ab.y);
    double scalBC = sqrt(bc.x * bc.x + bc.y * bc.y);

    double radians = acos(vector / (scalAB * scalBC));

    double angle = radians * (180.0 / PIE);

    return angle;
}

int main(void)
{
    int amountOfCalls;
    for(int step = 0; step < amountOfCalls; step++)
    {
        Point A, B, C;
        scanf("%lf %lf %lf %lf %lf %lf", &B.x, &B.y, &A.x, &A.y, &C.x, &C.y);
        printf("%0.20g\n", calculateAngle(A, B, C));
    }
    return 0;
}