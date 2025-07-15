#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start=NULL;
void insertatbeg()
{
    int x;
    struct node *tmp;
    printf("ENTER THE ELEMENT TO BE INSERTED :");
    scanf("%d",&x);
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        tmp->data=x;
        tmp->prev=NULL;
        tmp->next=NULL;
        start=tmp;
        printf("%d INSERTED IN THE BEGINNING ",x);
    }
    else
    {
        tmp->data=x;
        tmp->prev=NULL;
        tmp->next=start;
        start->prev=tmp;
        start=tmp;
        printf("%d INSERTED IN THE BEGINNING ",x);
    }
}
void insertatend()
{
    int x;
    struct node *tmp,*p;
    printf("ENTER THE NUMBER TO BE INSERTED :");
    scanf("%d",&x);
    tmp=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        tmp->data=x;
        tmp->prev=NULL;
        tmp->next=NULL;
        printf("%d INSERTED AT THE END ",x);
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        tmp->data=x;
        tmp->prev=p;
        p->next=tmp;
        tmp->next=NULL;
        printf("%d INSERTED AT THE END ",x);
    }
}
void deleteatbeg()
{
    struct node *tmp;
    if(start==NULL)
    {
        printf("THE LIST IS EMPTY ");
        return ;
    }
    else if(start->next==NULL)
    {
        tmp=start;
        printf("%d HAS BEEN DELETED FROM THE BEGINNING ",tmp->data);
        free(tmp);
        start=NULL;
    }
    else
    {
        tmp=start;
        printf("%d HAS BEEN DELETED FROM THE BEGINNING ",tmp->data);
        start=start->next;
        start->prev=NULL;
        free(tmp);
    }
}
void deleteatend()
{
    struct node *p;
    if(start==NULL)
    {
        printf("THE LIST IS EMPTY ");
        return ;
    }
    else if(start->next==NULL)
    {
        p=start;
        printf("%d IS DELTED FROM THE END ",p->data);
        free(p);
        start=NULL;
    }
    else
    {
        p=start;
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        printf("ELEMENT %d IS DELETED ",p->next->data);
        free(p->next);
        p->next=NULL;
    }

}
void insert_pos()
{
    struct node *tmp,*p;
    int x,i,pos;
    printf("ENTER THE ELEMENT TO BE INSERTED :");
    scanf("%d",&x);
    printf("ENTER THE POSITION TO BE INSERTED :");
    scanf("%d",&pos);
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=x;
    if(pos==1)
    {
        tmp->prev=NULL;
        tmp->next=start;
        if(start!=NULL)
        {
            start->prev=tmp;
        }
        printf("%d INSERTED AT POSITION %d ",x,pos);
    }
    else
    {
        p=start;
        for(i=1; i<pos-1 && p!=NULL; i++)
        {
            p=p->next;
        }
        if(p==NULL)
        {
            printf("THERE ARE LESS THAN %d ELEMENTS ",pos);
        }
        else
        {
            tmp->next=p->next;
            tmp->prev=p;
            if(p->next!=NULL)
            {
                p->next->prev=tmp;
            }
            p->next=tmp;
            printf("%d INSERTED AT %d ",x,pos);
        }

    }
}
int insert_afternode()
{
    struct node *tmp,*p;
    int x,item;
    printf("ENTER THE ELEMENT TO BE INSERTED :");
    scanf("%d",&x);
    printf("ENTER THE ELEMENT AFTER WHICH TO BE INSERTED :");
    scanf("%d",&item);
    p=start;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->data=x;
            tmp->next=p->next;
            if(p->next!=NULL)
            {
                p->next->prev=tmp;
            }
            p->next=tmp;
            tmp->prev=p;
            printf("%d INSERTED AFTER %d",x,item);
            return 0;
        }
        p=p->next;
    }
    printf("%d IS NOT PRESSENT IN THE LIST ",item);
    return 0;
}
void insert_beforenode()
{
    struct node *tmp,*p;
    int x,item;
    printf("ENTER THE ELEMENT TO BE INSERTED :");
    scanf("%d",&x);
    printf("ENTER THE ELEMENT BEFORE WHICH TO BE INSERTED ");
    scanf("%d",&item);
    if(start==NULL)
        printf("LIST IS EMPTY ");
    if(start->data==item)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->data=x;
        tmp->next=start;
        start->prev=tmp;
        tmp->prev=NULL;
        start=tmp;
        printf("%d INSERTED BEFORE %d",x,item);
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            if(p->next->data==item)
            {
                tmp=(struct node*)malloc(sizeof(struct node));
                tmp->data=x;
                tmp->next=p->next;
                p->next=tmp;
                tmp->prev=p;
                printf("%d INSERTED BEFORE %d\n",x,item);
                return ;
            }
            p=p->next;
        }
    }
    printf("%d IS NOT PRESENT IN THE LIST ",item);

}
void del_inbetween()
{
    int item;
    printf("ENTER THE ELEMENT TO BE DELETED :");
    scanf("%d",&item);
    struct node *p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(start->data==item)
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        printf("%d HAS BEEN DELETED ",tmp->data);
        free(tmp);
        return ;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            if(p->next->data==item)
            {
                tmp=p->next;
                p->next=tmp->next;
                if(p->next!=NULL)
                    tmp->next->prev=p;
                printf("%d HAS BEEN DELETED ",tmp->data);
                free(tmp);
                return ;
            }
            p=p->next;
        }
        printf("%d WAS NOT FOUND IN THE LIST ",item);
        return;
    }
}
void del_pos()
{
    int pos;
    printf("ENTER THE POSITION TO BE DELETED :");
    scanf("%d",&pos);
    struct node *tmp,*p;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf("THE LIST IS EMPTY");
        return ;
    }
    if(pos==1)
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        printf("%d HAS BEEN DELETED ",tmp->data);
        free(tmp);
        return ;
    }
    else
    {
        p=start;
        for(int i=1; i<pos-1 && p!=NULL ; i++)
        {
            p=p->next;
        }
        if(p==NULL)
        {
            printf("THERE ARE LESS THAN %d ELEMENTS ",pos);
            return ;
        }
        else
        {
            tmp=p->next;
            p->next=tmp->next;
            if(p->next!=NULL)
            {
                tmp->next->prev=p;
            }
            printf("%d HAS BEEN DELETED FROM THE LIST ",tmp->data);
            free(tmp);
        }
    }

}
int count()
{
    struct node *p;
    int cnt=0;
    p=start;
    while(p!=NULL)
    {
        p=p->next;
        cnt=cnt+1;
    }
    printf("NUMBER OF ELEMENTS ARE %d \n ",cnt);
    return 0;
}
void search()
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
            return ;
        }
        p=p->next;
        pos++;
    }
    printf("ITEM %d IS NOT FOUND IN THE LIST",element);
    return ;
}
void reverse()
{
    struct node *p1,*p2;
    p1=start;
    p2=start->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    printf("THE LIST HAS BEEN REVERSED");
    return ;
}
void display()
{
    struct node *p;
    p=start;
    printf("------------THE CONTENTS OF THE DOUBLY LINKED LIST ARE-----------\n");
    if(start==NULL)
    {
        printf("THE LIST IS EMPTY");
    }
    else
        while(p!=NULL)
        {
            printf(" %d ",p->data);
            p=p->next;
        }
    printf("\n --------------------------------------------------------\n ");
}
int main()
{
    int choice ;
    do
    {
        printf("\n****************************DOUBLY LINKED LIST MENU******************************");
        printf("\n1:INSERT AT BEGINNING\n2:INSERT AT END \n3:DELETE AT BEGINNING\n4:DELETE AT END\n5:INSERT AT A GIVEN POSITION\n6:INSERTION AFTER NODE\n7:INSERTION BEFORE NODE\n8:DELETION IN BETWEEN THE NODE \n9:DELETION AT GIVEN POSITION \n10:COUNT\n11:SEARCH\n12:REVERSE\n13:DISPLAY\n14:EXIT");
        printf("\nENTER THE OPERATION THAT YOU WANT :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            insertatbeg();
            break;
        }
        case 2:
        {
            insertatend();
            break;
        }
        case 3:
        {
            deleteatbeg();
            break;
        }
        case 4:
        {
            deleteatend();
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

