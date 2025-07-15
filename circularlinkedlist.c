#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *last=NULL;
void insertbeg()
{
    int x;
    printf("ENTER THE ELEMENT TO BE INSERTED : ");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(last==NULL)
    {
        tmp->data=x;
        last=tmp;
        last->link=last;
        printf("%d INSERTED AT THE BEGINNING",x);
    }
    else
    {
        tmp->data=x;
        tmp->link=last->link;
        last->link=tmp;
        printf("%d INSERTED AT THE BEGINNING ",x);
    }
}
void insertEmptyList()
{
    int x;
    printf("ENTER THE ELEMENT TO BE INSERTED : ");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(last==NULL)
    {
        tmp->data=x;
        last=tmp;
        last->link=last;
        printf("%d INSERTED ",x);
    }
    else
    {
        printf("LIST IS NOT EMPTY ");
        return;
    }
}
void insertatend()
{
    int x;
    printf("ENTER THE ELEMENT TO BE INSERTED ");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=x;
    if(last==NULL)
    {
        tmp->data=x;
        last=tmp;
        last->link=last;
        printf("%d INSERTED ",x);

    }
    else
    {
        tmp->link=last->link;
        last->link=tmp;
        last=tmp;
        printf("%d INSERTED AT THE END ",x);
    }
}
void insertafternode()
{
    int x,item;
    printf("ENTER THE ELEMENT TO BE INSERTED ");
    scanf("%d",&x);
    printf("ENTER THE ELEMENT AFTER WHHICH TO BE INSERTED ");
    scanf("%d",&item);
    struct node *tmp,*p;
    p=last->link;
    do
    {
        if(p->data==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->data=x;
            tmp->link=p->link;
            p->link=tmp;
            if(p==last)
            {
                last=tmp;
            }
            printf("%d INSERTED AFTER %d",x,item);
            return ;
        }
        p=p->link;
    }
    while(p!=last->link);
    printf("%d NOT PRESENT IN THE LIST ",item);
}
void del()
{
    int x;
    printf("ENTER THE ELEMENT TO BE DELETED ");
    scanf("%d",&x);
    struct node *p,*tmp;
    if(last==NULL)
    {
        printf("THE LIST IS EMPTY ");
        return ;
    }
    if(last->link==last && last->data==x)
    {
        tmp=last;
        last=NULL;
        free(tmp);
        printf("%d DELETED SUCCESSFULLY\n",x);
        return ;
    }
    if(last->link->data==x)
    {
        tmp=last->link;
        last->link=tmp->link;
        free(tmp);
        printf("%d DELETED SUCCESSFULLY\n",x);
        return ;
    }
    p=last->link;
    while(p->link!=last)
    {
        if(p->link->data==x)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            printf("%d DELETED SUCCESSFULLY ",x);
        }
        p=p->link;
    }
    if(last->data==x)
    {
        tmp=last;
        p->link=last->link;
        last=p;
        free(tmp);
        printf("%d DELETED SUCCESSFULLY \n",x);
    }
    printf("%d NOT FOUND ",x);
}
void display()
{
    struct node *p;
    if(last==NULL)
    {
        printf("LIST IS EMPTY ");
        return ;
    }
    p=last->link;
    do
    {
        printf("%d\t",p->data);
        p=p->link;

    }
    while(p!=last->link);
    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1.INSERT AT BEGINNING");
        printf("\n2.INSERT IN EMPTY LIST");
        printf("\n3.INSERT AT THE END OF THE LIST");
        printf("\n4.INSERT AFTER NODE");
        printf("\n5.ENTER THE ELEMENT TO BE DELETED ");
        printf("\n6.DISPLAY");
        printf("\nENTER YOUR CHOICE :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            insertbeg();
            break;
        }
        case 2:
        {
            insertEmptyList();
            break;
        }
        case 3:
        {
            insertatend();
            break;
        }
        case 4:
        {
            insertafternode();
            break;
        }
        case 5:
        {
            del();
            break;
        }
        case 6:
        {
            display();
            break;
        }
        case 7:
        {
            exit(1);
        }
        default:
            printf("WRONG CHOICE \n");
        }
    }
    while(choice!=7);
}

