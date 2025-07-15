#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;

void enqueue()
{
    int x;
    printf("ENTER THE ELEMENT TO BE INSERTED :");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("NO SPACE FOR DYNAMIC MEMORY ALLOCATION");
        return ;
    }
    tmp->data=x;
    if(front==NULL)
    {
        tmp->link=tmp;
        front=tmp;
    }
    else
    {

        tmp->link=front;
        rear->link=tmp;
    }
    rear=tmp;
    printf("%d INSERTED ",x);
}
void dequeue()
{
    struct node *tmp;
    if(front==NULL)
    {
        printf("THE LIST IS EMPTY");
        return ;
    }
    else if(front==rear)
    {
        tmp=front;
        printf("ELEMENT %d DELETED",front->data);
        free(tmp);
        front=rear=NULL;
        return ;

    }
    else
    {
        printf("ELEMENT %d DELETED",front->data);
        tmp=front;
        front=front->link;
        rear->link=front;
        free(tmp);

    }
}
void display()
{
    struct node *p;
    if(front==NULL)
    {
        printf("THE LIST IS EMPTY ");
        return ;
    }
    printf("\n------THE CONTENTS OF THE CIRCULAR QUEUE ARE----\n");
    p=front;
    do
    {
        printf("%d ",p->data);
        p=p->link;
    }
    while(p!=rear->link);
    printf("\n------------------------------------------------\n");
}
void isEmpty()
{
    if(front==NULL)
    {
        printf("THE LIST IS EMPTY ");
        return ;
    }
    else
        printf("THE QUEUE IS NOT EMPTY ");
    return ;
}
void peek()

{
    if(front==NULL)
    {
        printf("THE LIST IS EMPTY ");
        return ;
    }
    else
    {
        printf("THE FRONT ELEMENT IS : %d ",front->data);
    }
}

int main()
{
    int choice ;
    do
    {
        printf("\n*************MENU*************");
        printf("\n1:ENQUE\n2:DEQUEUE\n3:ISEMPTY\n4:PEEK\n5:DISPLAY\n6:EXIT ");
        printf("\nENTER THE OPERATION THAT YOU WANT :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            enqueue();
            break;
        }
        case 2:
        {

            dequeue();
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
        default:
            printf("INVALID CHOICE");
        }
    }
    while(choice!=6);
    return 0;

}
