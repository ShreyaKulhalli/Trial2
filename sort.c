void array_sort(int *a,char mode,int r)
{
    int i,j,k,temp;
    if(mode=='a')
    {
     printf("yayayyyayay2\n");
     for(k=0;k<r;k++)
        {
        printf("%d\t",*(a+k));
        }
        k=0;

    for(i=0;i<r-1;i++)
        for(j=0;j<r-i-1;j++)
        if(a[j]>a[j+1])
        {
            printf("yayayyyayay3\n");
            temp=a[j];
            a[j]=a[j+1];
           a[j+1]=temp;
        }
    }
    else
    {
     for(i=0;i<r-1;i++)
        for(j=0;j<r-i-1;j++)
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
           a[j+1]=temp;
        }
    }
}
