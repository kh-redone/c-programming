#include<stdio.h>
int main()
{
    int i =8;
    int j=5;
    float x=0.005f;
    float y=-0.01f;
    char c= 'c';
    char d= 'd';
    printf("ex1 = %d\n",(3*i -2*j)%(2*d-c));
    printf("ex2 = %d\n", (2*((i/5) + (4*(j-3))%(i + j - 2))));
    printf("ex3 = %i\n",i<=j);
    printf("ex4 = %i\n", i!=6);
    printf("ex5 = %i\n", c==99);
    printf("ex6 = %i\n", 5*(i + j) > 'c');
    printf("ex7 = %i\n", (i > 0) && (j < 5));
    printf("ex8 = %i\n", (i > 0) || (j < 5));
    printf("ex9 = %i\n", (x > y) && (i > 0) || (j < 5));
    printf("ex10 = %i\n", (x > y) && (i > 0) && (j < 5));
    
    
    
}

    
