#include<stdio.h>
#include<stdlib.h>

// function memchr
void* al_memchr(void* array, int c, int n){
    char* arr = (char*) array;
    for(int i=0;i<n;i++){
        if( arr[i] ==  c)
            return array + i;
    }
    return NULL;
}

// function memset
void* al_memset(void *array, int c, int n){
    char* arr = (char*) array;
    for(int i=0;i<n;i++){
        arr[i] = c;
    }
    return arr;
}
// function memcpy
void* al_memcpy(void *dest, void * src, int n){
    char* dest1 = (char *) dest;
    char* src1 = (char *) src;
    for(int i=0;i<n;i++)
        dest1[i] = src1[i];
    return dest1;
}
// function memmove
void* al_memmove(void * dest, void * src,int n){
    char* dest1 = (char *) dest;
    char* src1 = (char *) src;
    char temp[n];
    for(int i=0;i<n;i++)
        temp[i] = src1[i];
    for(int i=0;i<n;i++)
        dest1[i] = temp[i];
    return dest1;
}
// function strdup
char* al_strdup(const char *s){
    int n = al_strlen(s);
    char* copy = (char*)malloc(n*sizeof(char));
    for(int i=0;i<n;i++)
        copy[i] = s[i];
    copy[n] = '\0';
    return copy;
}


