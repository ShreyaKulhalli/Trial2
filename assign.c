void array_assign(int *a,int r)
{
    int i,k;
    for(i=0;i<r;i++)
    {
        a[i]=rand()%50;
    }
    printf("yayayyyayay2\n");
    for(k=0;k<r;k++)
        {
        printf("%d\t",*(a+k));
        }k=0;
}
