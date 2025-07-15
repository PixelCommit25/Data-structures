#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
void insert()
{
    int x ;
    printf("ENTER THE NUMBER TO BE INSERTED :");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("NO MEMORY AVAILABLE ");
        return ;
    }
    tmp->data=x;
    tmp->link=NULL;
    if(front==NULL)
    {
        front=tmp;
    }
    else
    {
    rear->link=tmp;
    }
    rear=tmp;
    printf(" %d INSERTED",x);
}
void del()
{
    struct node *tmp;
    if(front==NULL)
    {
        printf("THE QUEUE IS EMPTY ");
        return ;
    }
    printf("DELETED ELEMENT IS %d",front->data);
    tmp=front;
    front=front->link;
    free(tmp);
}
void peek()
{
    if(front==NULL)
    {
        printf("QUEUE UNDERFLOW ");
        return;
    }
    printf("ELEMENT AT THE FRONT IS %d \n ",front->data);
}
void isEmpty()
{
    if(front==NULL)
    {
        printf("QUEUE IS EMPTY");
        return ;
    }
    printf("THE QUEUE IS NOT EMPTY ");
}
void display()
{
    struct node *p=front;
    if(front==NULL)
    {
        printf("LIST IS EMPTY");
        return ;
    }
    else
        p=front;
        printf("-------CONTENTS OF THE QUEUE ARE :-----------\n");
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->link;
    }
    printf("\n---------------------------------------------");
}
int main()
{
    int choice ;
    do
    {
        printf("\n1:ENQUE\n2:DEQUEUE\n3:ISEMPTY\n4:PEEK\n5:DISPLAY\n6:EXIT ");
        printf("\n ENTER THE OPERATION THAT YOU WANT :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            del();
            break;
        }
        case 3:
        {
            isEmpty();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            printf("EXITED");
            exit(1);
            break;
        }
        default:printf("INVALID CHOICE");
        }
    }
    while(choice!=6);
    return 0;
}
