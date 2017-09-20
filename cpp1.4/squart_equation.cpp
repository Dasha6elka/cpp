#include <cstdio>
#include <math.h>

int main()
{
    std::puts("please enter a and b and c for 'ax^2 + bx + c = 0':");

    float a=0;
    float b=0;
    float c=0;

    std::scanf("%f %f %f", &a, &b, &c);

    float d=(b*b)-(4*a*c);
    
    if (d>0)
    {
        float x1=(-b+sqrt(d)/2*a);
        float x2=(-b-sqrt(d)/2*a);
        std::printf("solution: %f\n", x1);
        std::printf("solution: %f\n", x2);
    }
    else if (d==0)
    {
        float x=(-b)/2*a;
        std::printf("solution: %f\n", x);
    }
    else
    {
        std::printf("no");
    }
}