#include<stdio.h>
#include<stdlib.h>
#include"Array_functions.h"
#define ROWS 10
#define MODE 'a'
int *al;
    int rows=ROWS,k;
    char mode=MODE;
int main()
{

    array_create(al,rows);
    //array_assign(array_pointer,rows);
    //array_sort(array_pointer,mode,rows);
    for(k=0;k<rows;k++)
    {
        printf("%d\t",al[k]);
    }
    k=0;
    printf("ARRAY\n");
    for(k=0;k<rows;k++)
    {
        printf("%d\t",al[k]);
    }
    k=0;
    printf("\n");
 /*   //if(mode=='a')
    {
        array_sort(a,mode,rows);
        printf("Array in Ascending order:\t");
        for(k=0;k<rows;k++)
        {
        printf("%d\t",a[k]);
        }k=0;
    }
    /*else
        {
        array_sort(array_pointer,mode,rows);
        printf("Array in Descending order:\t");
        for(k=0;k<rows;k++)
        {
        printf("%d\t",array_pointer[k]);
        }k=0;
    }*/
}
