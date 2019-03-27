void array_create(int *a,int r)
{
    int p;
    a=calloc(r,sizeof(int));
    for(p=0;p<r;p++)
        {
        printf("%d\t",*(a+p));
        }

    printf("yayayyyayay1\n");
}
