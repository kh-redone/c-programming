#include<stdio.h>
#include<stdlib.h>

// function strlen
int al_strlen(char* str)
{
	int n=0;
    while(str[n] != '\0')  n++;
    return n;
}
// function strcpy
char* al_strcpy(char* str1, char* str2)
{
    int n = al_strlen(str2);
    for(int i=0 ; i<n ; i++)  str1[i] = str2[i];
    str1[n] = '\0';
    return str1;
} 
// function strcat
char* al_strcat(char* str1, char* str2){
    int n = al_strlen(str1);
    int m = al_strlen(str2);
    for(int i=0 ; i<m ; i++)  str1[n+i]=str2[i];
    str1[n+m] = '\0';
    return str1;
}
// function reverseString
void reverseString(char* str)
{
    int n = al_strlen(str); char temp;
    for(int i=0;i<n/2;i++)
    {
        temp=str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}
// function wreverse
 void str_wreverse(char * str1)
 {
    char str2[10][10]; 
    int j=0, ctr=0, i=0;
    for(i=0; i<= (al_strlen(str1)) ; i++)
    {
        if(str1[i]==' '||str1[i]=='\0')
        {
            str2[ctr][j]='\0';
            ctr++;
            j=0;
        }
        else
        {
            str2[ctr][j]=str1[i];
            j++;
        }
    }
    for(i=ctr ; i<10 ; i++)
        for(j=0;j<10;j++) str2[i][j] = '\0';
    for(i=0 ; i<10 ; i++) reverseString(str2[i]); 
    for(i=0;i<10;i++) printf("%s ",str2[i]); 
    return;
}


int main(){
    char str[10];
    printf("Enter a string : ");
    gets(str);
    printf("the size of the previous string is : %d\n",al_strlen(str));
    printf("Enter another string : ");
    gets(str);
    reverseString(str);
    printf("the inverted string is : %s\n",str);
    char copy[10];
    al_strcpy(copy,str);
    printf("the copy of the previous string is : %s\n",copy);
    printf("Enter two strings : \n");
    char copy1[10], copy2[10];
    printf("1st string : "); gets(copy1);
    printf("2nd string : "); gets(copy2);
    al_strcat(copy1,copy2);
    printf("the concatenation of the previous two strings is : %s\n",copy1);
    printf("Enter a string to inverse word by word : \n");
    char str1[50];
    gets(str1);
    char newString[10][10];
    str_wreverse(str1);
    return 0;
}








