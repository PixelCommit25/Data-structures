#include<stdio.h>
int binarysearch(int [],int,int);
int main()
{
    int a[10],index,item,size,i;
    printf("Enter the number of elements :");
    scanf("%d",&size);
    printf("\n ENTER THE ELEMENTS IN SORTED ORDER \n ");
    for(i=0; i<size; i++)
    {
        printf("Enter element %d :",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n Enter the number to be searched :");
    scanf("%d",&item);
    index=binarysearch(a,size,item);
    if(index==-1)
        printf("\n Number not found");
    else
        printf("\n Number found at location %d",index);
    return 0;
}
int binarysearch(int a[],int size,int item )
{
    int low=0,up=size-1,mid;
    while(low<=up)
    {
        mid=(low+up)/2;
        if(item>a[mid])
            low=mid+1;
        else if(item<a[mid])
            up=mid-1;
        else
            return mid;
    }
    return -1;
}
