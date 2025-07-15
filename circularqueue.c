#include<stdio.h>
#include <windows.h>
void insert(int );
void del(int);
void display(int );
int front =-1;
int rear=-1;
int a[10];
int main()
{
        int n,choice,element;
    printf("ENTER THE NUMBER OF ELEMENTS : ");
    scanf("%d",&n);
    do{
       printf("\n\t1:INSERT\t2:DELETE\t3:DISPLAY\t4:PEEK\t5:COUNT\t6:EXIT\n ") ;
       printf("ENTER YOUR CHOICE : ");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:
        {
            insert(n);
         break;
        }
        case 2:
        {
         del(n);
         break;
        }
        case 3:
        {
         display(n);
         break;
        }
        case 4:
        {
            printf("\n\n\tEXITED\n\n");
         break;
         }
        default: printf("INVALID CHOICE");
       }
      }while(choice!=4);
    return 0;
}
void insert(int n)
{
    int element;
    if((rear+1)%n==front)//((front==0 && rear==n-1)||front==rear+1;)
    {
        printf("Q OVERFLOW");
        return;
    }
    else if(front==-1 && rear==-1)
    {
    printf("\nENTER ELEMENT TO BE INSERTED :");
    scanf("%d",&element);
        front=0;
        rear=0;
        a[rear]=element;
    }
    else
        {
            printf("\nENTER ELEMENT TO BE INSERTED :");
            scanf("%d",&element);
            rear=(rear+1)%n;
            a[rear]=element;
        }
}
void del(int n)
{
    if(front==-1)
    {
        printf("q is empty");
    }
    else if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else{
    front=(front+1)%n;}

}
void display(int n)
{
    int i;
    while(i!=rear)
    {
        printf("%d ",a[i]);
        i=((i+1)%n)+1;
    }
}
