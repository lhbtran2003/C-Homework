#include<stdio.h>
typedef struct{
    double re;
    double im;
}complex;

void addComplex(complex *a, complex *b, complex *c){
    (*c).re = (*a).re + (*b).re;
    (*c).im = (*a).im + (*b).im;
}

void printComplex(complex c)
{
    printf("%f + %f ", c.re, c.im);
}

int main(){
    complex x= {1.2,3.4};
    complex y= {5.6,7.8};
    complex z;
    complex *p1 = &x;
    complex *p2 = &y;
    complex *p3 = &z;
    addComplex(p1, p2, p3);
    printComplex(z);


}
