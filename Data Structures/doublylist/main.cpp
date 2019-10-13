#include <iostream>

using namespace std;

struct node
{
    int value;
    node*next;
    node*prev;
}*start=NULL;

void insertd()
{
    int ch,pos;
    node*temp;
    node*temp1;

     cout<<"\n Enter the value you want to insert\t";
     cin>>v;
     cout<<"\n 1.\tInsert at beginning \n 2.\tInsert at middle \n 3.\tInsert at end";
     cin>>ch;

     temp->value=v;
     temp->next=NULL;
     temp->prev=NULL;

     if(start==NULL)
      {
        start->value=v;
        start->next=NULL;
        start->prev=NULL;
      }
      else if(ch==1)
      {
         temp->next=start;
         temp->prev=NULL;
         temp=start;

      }
      else if(ch==2)
      {
          cout<<"\n Enter the position at which you want to insert\t";  //To Be Checked
          cin>>pos;

      }
      else if(ch=3)
      {
          temp1=start;
          while(temp1->next!=NULL)
            temp1=temp1->next;

          temp1->next=temp;
          temp->prev=temp1;

      }


}

void deleted()
{
   int ch,pos;
   node*temp;

   cout<<"\n 1.\tDelete at beginning \n 2.\tDelete at middle \n 3.\tDelete at end";
   cin>>ch;

   if(start==NULL)
    cout<<"\nUNDERFLOWW!!!!\n";
   else if(ch==1)
   {
       temp=start;
       start=start->next;
       start->prev=NULL;
       delete(temp);
   }
   else if(ch==2)
   {
       cout<<"\n Enter the position at which you want to delete\n";  //To Be Checked
       cin>>pos;
   }
   else if(ch==3)
   {
       while(temp->next!=NULL)
        temp=temp->next;

       temp->prev=NULL;
       delete(temp);
   }
}

void displayd()
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
        insertd();
      else if(ch==2)
        deleted();
       else if(ch==3)
         displayd();
       else
        return 0;
    }


    return 0;
}
