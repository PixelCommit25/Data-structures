#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;
void push()
{
    int x;
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("NO SPACE FOR DYNAMIC ALLOCATION !! ");
    }
    else
        printf("ENTER THE NUMBER TO BE INSERTED IN THE STACK ");
    scanf("%d",&x);
    {
        tmp->link=top;
        tmp->data=x;
        top=tmp;
        printf("%d INSERTED IN THE STACK ",x);
    }
}
void pop()
{
    struct node *p;
    if(top==NULL)
    {
        printf("LIST IS EMPTY");
    }
    else
    {
        printf("ELEMENT %d HAS BEEN POPPED \n ",top->data);
        p=top;
        top=top->link;
        free(p);
    }
}
void display()
{
    struct node *p;
    p=top;
    if(top==NULL)
    printf("THE LIST IS EMPTY");
    else
        printf("------------THE CONTENTS OF THE STACK ARE-----------\n");
        while(p!=NULL)
        {
            printf("\t\t%d\n",p->data);
            p=p->link;
        }
    printf("-------------------------------------------------------- ");
}
void peek()
{
    struct node *p;
    if(top==NULL)
    {
        printf("THE LIST IS EMPTY");
    }
    else
        printf("THE TOP MOST ELEMENT IS %d ",top->data);
}
void isEmpty()
{
    if(top==NULL)
    {
        printf("THE LIST IS EMPTY");
    }
    else
        printf("THE LIST IS NOT EMPTY ");
}
int main()
{
    int choice ;
    do
    {
        printf("\n1:PUSH\n2:POP\n3:ISEMPTY\n4:PEEK\n5:DISPLAY\n6:EXIT ");
        printf("\n ENTER THE OPERATION THAT YOU WANT :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
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
        default:printf("INVALID CHOICE ");
        }
    }
    while(choice!=6);
    return 0;
}

