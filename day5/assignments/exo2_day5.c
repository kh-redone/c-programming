#include<stdio.h>
#include<stdlib.h>


void printArray(int* arr, int n){
    printf("[");
    for(int i=0;i<n;i++)
        printf("%d, ",arr[i]);
    printf("\b\b]\n");
}


void isort(int **arr, size_t length){
	for(int i = 0 ; i<length-1 ; i++){
		int mini=(*arr)[i],index_mini=i;
		for(int j = i+1 ; j<length ; j++)
		{
			if((*arr)[j] < mini)
			{
				mini=(*arr)[j];
				index_mini=j;
			}
		}
		(*arr)[index_mini]=(*arr)[i];
		(*arr)[i]=mini;
	}
}

int main(){
    int n;
    printf("the size of the array is : ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("the component of the array are:   ");
    for(int i=0;i<n;i++)
         scanf("%d",&arr[i]);
    printf("Unsorted Array: ");
    printArray(arr,n);
    isort(&arr,n);
    printf("Sorted Array  : ");
    printArray(arr,n);
    free(arr);
    return 0;
}
