#include <iostream>
#include <stdio.h>

int main()
{
    float a,b,c,d;
    float sum_plus, sum_minus = 0;

    scanf("%f%f%f%f",&a, &b, &c, &d);

    if (a > 0)
    {
        sum_plus += a;
    }
    else {
        sum_minus += a;
    }
    if (b > 0) {
        sum_plus += b;
    }
    else {
        sum_minus += b;
    }
    if (c>0) {
        sum_plus += c;
    }
    else {
        sum_minus += c;
    }
    if (d>0) {
        sum_plus += d;
    }
    else {
        sum_minus += d;
    }
    printf("%.1f\t%.1f", sum_plus, sum_minus);

    return 0;
}