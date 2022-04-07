#include<stdio.h>
#include<stdlib.h>

// create stuct complex
struct complex
{
    float real;
    float imaginary;
};
typedef struct complex complex;



// create function of printing the complex number
void print(complex a){
	printf("%f + %f i\n",a.real,a.imaginary);
	return;
}




complex add(complex a, complex b){
	complex c;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return c;
}




complex sub(complex a,complex b){
	complex c;
	c.real = a.real - b.real;
	c.imaginary = a.imaginary - b.imaginary;
	return c;
}





complex mul(complex a, complex b){
	complex c;
	c.real = a.real*b.real - a.imaginary*b.imaginary;
	c.imaginary = a.imaginary*b.real + a.real*b.imaginary;
	return c;
}




complex division(complex a, complex b){
	if(b.real == 0 && b.imaginary == 0){
		printf("division by zero\n");
		complex c = {0,0};
		return c;
	}
	complex c;
	c.real = (a.real*b.real + a.imaginary*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	c.imaginary = (a.imaginary*b.real-a.real*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	return c;
}


// The main function
int main(){
    complex a = {-2,4};
    complex b = {7,-9};
    complex c = add(a,b);
    complex d = sub(a,b);
    complex e = mul(a,b);
    complex f = division(a,b);
    printf("a = "); print(a);
    printf("b = "); print(b);
    printf("a + b = ") ; 
    print(c);
    printf("a - b = ") ;
    print(d);
    printf("a * b = ") ; 
    print(e);
    printf("a / b = ") ; 
    print(f);
    return 0; 
}
