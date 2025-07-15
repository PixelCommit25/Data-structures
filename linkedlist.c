#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start=NULL;
int insertbeg()
{
    int x;
    printf("ENTER THE NUMBER TO BE INSERTED AT THE BEGINNING : ");
    scanf("%d",&x);
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    if(start==NULL)
    {
        temp->data=x;
        temp->link=NULL;
        start=temp;
        printf("%d INSERTED AT THE BEGINING ",x);
        return 0;
    }
    else
    {
        temp->link=start;
        temp->data=x;
        start=temp;
        printf("%d INSERTED AT THE BEGINNING",x);
        return 0;
    }
}
int insertend()
{
    int x;
    printf("ENTER THE ELEMENT TO BE INSERTED AT THE END :");
    scanf("%d",&x);
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        temp->link=NULL;
        temp->data=x;
        start=temp;
        printf("%d INSERTED AT THE END",x);
        return 0;
    }
    else
    {
        p=start;
        while(p->link!=0)
        { p=p->link;}
            p->link=temp;
            temp->link=NULL;
            temp->data=x;
            printf(" %d ELEMENT INSERTED AT THE END ",x);
            return 0;
    }
}
int deletebeg()
{
    struct node *p;
    if(start==NULL)
    {
        printf(" LIST IS EMPTY");
        return 0;
    }
    else if(start->link==NULL)
    {
        p=start;
        printf("%d HAS BEEN DELETED ",p->data);
        free(p);
        start=NULL;
        return 0;
    }
    else
    {
        printf("ELEMENT %d IS DELETED FROM BEGINING \n ",start->data);
        p=start;
        start=start->link;
        free(p);
        return 0;
    }
}
int delete_end()
{
    struct node *p;
    if(start==NULL)
    {
        printf("THE LIST IS EMPTY");
        return 0;
    }
    else if(start->link==NULL)
    {
        p=start;
        printf("%d IS DELETED FROM END ",p->data);
        free(p);
        start=NULL;
        return 0;
    }
    else
    {
        p=start;
        while(p->link->link!=NULL)
        {
            p=p->link;
        }
        printf("ELEMENT %d DELETED FROM END",p->link->data);
        free(p->link);
        p->link=NULL;
        return 0;
    }
}
int insert_pos()
{
    struct node *p,*tmp;
    int i;
    int x,pos;
    printf("ENTER THE ELEMENT TO BE INSERTED :");
    scanf("%d",&x);
    printf("ENTER THE POS :");
    scanf("%d",&pos);
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=x;
    if(pos==1)
    {
        tmp->link=start;
        start=tmp;
        return 0;
    }
    else
    {
    p=start;
    for(i=1; i<pos-1 && p!=NULL; i++)
        p=p->link;
    if(p==NULL)
        printf("THERE ARE LESS THAN %d ELEMENTS",pos);
    else
    {
        tmp->link=p->link;
        p->link=tmp;
    }
    }
    return 0;
}
int insert_afternode()
{
    struct node *tmp,*p;
    int element,item;
    printf("ENTER THE ELEMENT TO BE INSERTED :");
    scanf("%d",&element);
    printf("ENTER THE ELEMENT AFTER WHICH TO BE INSERTED :");
    scanf("%d",&item);
    p=start;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->data=element;
            tmp->link=p->link;
            p->link=tmp;
            return 0;
        }
        p=p->link;
    }
    printf("%d IS NOT PRESENT IN THE LIST",item);
    return 0;
}
int insert_beforenode()
{
    struct node *p,*tmp;
    int element,item;
    printf("ENYER THE ELEMENT TO INSERTED :");
    scanf("%d",&element);
    printf("ENTER THE ELEMENT BEFORE TO BE INSERTED :");
    scanf("%d",&item);
    if(start==NULL)
    {
        printf("LIST IS EMPTY");
        return 0;

    }
    if (item==start->data)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->data=element;
        tmp->link=start;
        start=tmp;
        return 0;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->data==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->data=element;
            tmp->link=p->link;
            p->link=tmp;
            return 0;

        }
        p=p->link;
    }
    printf("ELEMENT IS NOT PRESENT  ");
    return 0;
}
int del_inbetween()
{
    struct node *p,*tmp;
    int element;
    printf("ENTER THE ELEMENT TO BE DELETED ");
    scanf("%d",&element);
    if(start==NULL)
    {
        printf("LIST IS EMPTY");

    }
    if(start->data==element)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return 0;

    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->data==element)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return 0;

        }
        p=p->link;
    }
    printf("ELEMENT NOT FOUND");
    return 0;
}
int del_pos()
{
    struct node *tmp,*p;
    int pos,i;
    printf("ENTER THE POSITION TO BE DELETED");
    scanf("%d",&pos);
    if(start==NULL)
    {
        printf("THE LIST IS EMPTY");
    }
    if(pos==1)
    {
        p=start;
        start=start->link;
        free(p);
        return 0;
    }
    p=start;
    for(i=0; i<pos-2 && p!=NULL; i++)
    {
        p=p->link;
    }
    if(p==NULL)
    {
        printf("THERE ARE LESS ELEMENTS THE LIST");
        return 0;
    }
    else
    {
        tmp=p->link;
        p->link=p->link->link;
        printf("%d DELETED FROM THE LIST AT POSITION %d",tmp->data,pos);
        free(tmp);
        return 0;
    }
}
int count()
{
    struct node *p;
    int cnt=0;
    p=start;
    while(p!=NULL)
    {
        p=p->link;
        cnt=cnt+1;
    }
    printf("NUMBER OF ELEMENTS ARE %d \n ",cnt);
    return 0;
}
int search()
{
    struct node *p;
    int pos=1,element;
    printf("ETER THE ELEMENT TO BE SEARCHED :");
    scanf("%d",&element);
    p=start;
    while(p!=NULL)
    {
        if(p->data==element)
        {
            printf("ITEM %d FOUND AT POSITION : %d \n",element,pos);
            return 0;
        }
        p=p->link;
        pos++;
    }
    printf("ITEM %d IS NOT FOUND IN THE LIST",element);
    return 0;
}
void display()
{
    struct node *p;
    p=start;
    printf("------------THE CONTENTS OF THE LINKED LIST ARE-----------\n");
    if(start->link==NULL)
    {
        printf(" %d ",start->data);
    }
    else
        while(p!=NULL)
        {
            printf(" %d ",p->data);
            p=p->link;
        }
    printf("\n --------------------------------------------------------\n ");
}
int reverse()
{
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    printf("THE LINKED LIST IS REVERSED");
    return 0;
}
int main()
{
    int choice ;
    do
    {   printf("\n****************************LINKED LIST MENU******************************");
        printf("\n1:INSERT AT BEGINING\n2:INSERT AT END \n3:DELETE AT BEGINNING\n4:DELETE AT END\n5:INSERT AT A GIVEN POSITION\n6:INSERTION AFTER NODE\n7:INSERTION BEFORE NODE\n8:DELETION IN BETWEEN THE NODE \n9:DELETION AT GIVEN POSITION \n10:COUNT\n11:SEARCH\n12:REVERSE\n13:DISPLAY\n14:EXIT");
        printf("\n ENTER THE OPERATION THAT YOU WANT :");
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
            insertend();
            break;
        }
        case 3:
        {
            deletebeg();
            break;
        }
        case 4:
        {
            delete_end();
            break;
        }
        case 5:
        {
            insert_pos();
            break;
        }
        case 6:
        {
            insert_afternode();
            break;
        }
        case 7:
        {
            insert_beforenode();
            break;
        }
        case 8:
        {
            del_inbetween();
            break;
        }
        case 9:
        {
            del_pos();
            break;
        }
        case 10:
        {
            count();
            break;
        }
        case 11:
        {
            search();
            break;
        }
        case 12:
        {
            reverse();
            break;
        }
        case 13:
        {
            display();
            break;
        }
        case 14:
        {
            printf("EXITED ");
        }
        }
    }
    while(choice!=14);
    return 0;
}
