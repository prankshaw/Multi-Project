#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node
{
    int value;
    struct node *next;
}*start=NULL;

void insertb()
 {   int v,ch;
     //int pos;
     struct node *newnode,*temp1;

     printf("\n Enter the value you want to insert\t");
     scanf("%d",&v);
     printf("\n 1.\tInsert at beginning \n 2.\tInsert at middle \n 3.\tInsert at end");
     scanf("%d",&ch);
    newnode=(struct node*)malloc(sizeof(struct node));
     newnode->value=v;
     newnode->next=NULL;

     if(start==NULL)
        start=newnode;
     else if(ch==1)
     {
         newnode->next=start;
         start=newnode;
     }
     /*else if(ch==2)
     {
         cout<<"enter the position at which you want to insert";         //To Be Checked
         cin>>pos;
         temp1=start;
         prev=temp1;
         while(pos)
         {
             temp1=temp1->next;
             prev=temp1;
         }
         temp1=temp1->next;
         prev->next=temp;
         temp->next=temp1;
     }*/
     else if(ch==3)
     {
         temp1=start;
         while(temp1->next!=NULL)
            temp1=temp1->next;
         temp1->next=newnode;

     }
     else
        printf("\nWrong value entered");

}

void deleteb()
{    int ch;
     //int pos;
     struct node *temp,*prev;

     printf("\n 1.\tDelete at beginning \n 2.\tDelete at middle \n 3.\tDelete at end");
     scanf("%d",&ch);


     if(start==NULL)
      {
         printf("\nUNDERFLOW!!!!\n");
      }
     else if(ch==1)
     {
         temp=start;
         start=start->next;
         free(temp);

     }
     /*else if(ch==2)
     {
         cout<<"enter the position at which you want to insert";      //To Be Checked
         cin>>pos;

     }*/
     else if(ch==3)
     {
         temp=start;
         while(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
         prev->next=NULL;
         free(temp);
     }
     else
        printf("\nWrong value entered");

}

void displayb()
{
 struct node *temp;
 temp=start;
 printf("\n");
 while(temp!=NULL)
    {
        printf("%d<-",temp->value);
        temp=temp->next;
    }

}


int main()
{
    int ch;

    printf("\n enter the operation with which you want to proceed\t");
    while(1)
    {
     printf("\n 1.\tInsert  \n 2.\tDelete \n 3.\tDisplay");
     scanf("%d",&ch);
      if(ch==1)
        insertb();
      else if(ch==2)
        deleteb();
       else if(ch==3)
         displayb();
       else
        return 0;
    }


    return 0;
}
