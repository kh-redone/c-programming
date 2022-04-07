#include<stdio.h>
#include<stdlib.h>

struct IntandString
{
    int intt;
    char* string;
};

typedef struct IntandString IntandString;


void swap(IntandString* a, IntandString* b){
	int temp1 = a->intt;
	a->intt = b->intt;
	b->intt = temp1;
	char* temp2 = a->string;
	a->string = b->string;
	b->string = temp2;
	return;
}

int main(){
	IntandString a,b;
	a.intt = 2003;
	a.string = "khemisse";
	b.intt = 1234;
	b.string = "redone";
	printf("before : \n");
	printf("a = %d %s\n",a.intt,a.string);
	printf("b = %d %s\n",b.intt,b.string);
	swap(&a,&b);
	printf("after : \n");
	printf("a = %d %s\n",a.intt,a.string);
	printf("b = %d %s\n",b.intt,b.string);

	return 0;
}
