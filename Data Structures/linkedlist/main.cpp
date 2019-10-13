#include <iostream>

using namespace std;

struct node
{
    int value;
    node*next;
}*start=NULL;

 void insertb()
 {   int v,ch,pos;
     node*temp;
     node*prev;
     node*temp1;

     cout<<"\n Enter the value you want to insert\t";
     cin>>v;
     cout<<"\n 1.\tInsert at beginning \n 2.\tInsert at middle \n 3.\tInsert at end";
     cin>>ch;

     temp->value=v;
     temp->next=NULL;

     if(start==NULL)
        start=temp;
     else if(ch==1)
     {
         temp->next=start;
         temp=start;
     }
     else if(ch==2)
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
     }
     else if(ch==3)
     {
         temp1=start;
         while(temp1->next!=NULL)
            temp1=temp1->next;
         temp1->next=temp;

     }
     else
        cout<<"\nWrong value entered";

}

void deleteb()
{    int ch,po
     node*temp;

     cout<<"\n 1.\tDelete at beginning \n 2.\tDelete at middle \n 3.\tDelete at end";
     cin>>ch;


     if(start==NULL)
      {
         cout<<"\nUNDERFLOW!!!!\n";
      }
     else if(ch==1)
     {
         temp=start;
         start=start->next;
         delete(temp);

     }
     else if(ch==2)
     {
         cout<<"enter the position at which you want to insert";      //To Be Checked
         cin>>pos;

     }
     else if(ch==3)
     {
         temp=start;
         while(temp->next!=NULL)
            temp=temp->next;
         delete(temp);
     }
     else
        cout<<"\nWrong value entered";

}

void displayb()
{
 node*temp;
 temp=start;
 cout<<"\n";
 while(temp!=NULL)
    {
        cout<<temp->value<<"\n";
        temp=temp->next;
    }

}


int main()
{
    int ch;

    cout<<"\n enter the operation with which you want to proceed\t";
    while(1)
    {
     cout<<"\n 1.\tInsert  \n 2.\tDelete \n 3.\tDisplay";
     cin>>ch;
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
