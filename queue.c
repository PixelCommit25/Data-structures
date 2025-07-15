#include<stdio.h>
#include <windows.h>
void insert(int );
void box(int n);
void del();
void peek();
void count();
//void gotoxy(float,float);
void display();
int front =-1;
int rear=-1;
int a[10];
int main()
{
    hideCursor();
    int n,choice;
    printf("ENTER THE NUMBER OF ELEMENTS : ");
    scanf("%d",&n);
    //box(n);
    do{
       printf("\n  1:INSERT  2:DELETE  3:DISPLAY  4:PEEK  5:COUNT  6:EXIT\n ") ;
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
         del();
         break;
        }
        case 3:
        {
         display();
         break;
        }
        case 4:
        {
         peek();
         break;
        }
        case 5:
            {
                count();
         break;
            }
            case 6:
                {
            printf("\n\n\tEXITED\n\n");
         break;
         }
        default: printf("INVALID CHOICE");
       }
      }while(choice!=6);
    return 0;
}
void insert(int n)
{
    int element;
    if(rear==n-1)
    {
        printf("Q OVERFLOW");
    return ;
    }
     printf("\nENTER ELEMENT TO BE INSERTED :");
    scanf("%d",&element);
    if(front==-1 && rear==-1)
    {
        rear=0;
        front=0;
        a[rear]=element;
    }
        else
        {
         rear=rear+1;
         a[rear]=element;
        }
}
void del(int n)
{
    int item;
    if(front==-1 && rear==-1)
        printf("queue underflow");
    else if(rear==front)
    {
        rear=-1;
        front=-1;
    }
    else
    {
        front=front +1;
    }
}
void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("IT IS EMPTY");
    }
    else

        printf("THE TOP MOST ELEMENT IS : %d ",a[front]);
}
void count()
{
    if(front==-1 && rear==-1)
    {
        printf("THERE ARE NO ELEMENTS");
    }
    else if(front==rear)
    {
        printf(" THERE IS ONLY 1 ELEMENT IN THE QUEUE");
        return;
    }
    else
    {
        int c=0;
    for(int i=front;i<=rear;i++)
    {
        c=c+1;
    }
    printf("\nTHERE ARE %d ELEMENTS IN THE QUEUE",c);
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("QUEUE IS EMPTY");
    }

    for(i=front;i<=rear;i++)
        printf(" %d ",a[i]);
}
void gotoxy(float x,float y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void box(int n)
{
    gotoxy(33,2);
    for(int i=1;i<(8*n)-(n-2);i++)
    {
        printf("-");
    }
    gotoxy(30,3);
    for(int x=1;x<=n+1;x++)
    {
        printf("   |   ");
    }
    gotoxy(30,4);
    for(int x=1;x<=n+1;x++)
    {
        printf("   |   ");
    }
    gotoxy(30,5);
    for(int x=1;x<=n+1;x++)
    {
        printf("   |   ");
    }

    gotoxy(33,6);
    for(int i=1;i<(8*n)-(n-2);i++)
    {
        printf("-");
    }
}
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

