#include <iostream>

using namespace std;

struct node
{
    int value;
    node*next;
}*frontq=NULL,*rear=null;

void insertq()
{
    intv;
    node*temp;

    cout<<"\n Enter the value you want to insert\t";
    cin>>v;

    temp->value=v;
    temp->next=NULL;

    if(frontq==NULL)
    {

       frontq->value=v;
       frontq->next=NULL;
       rear=frontq;
    }
    else
    {
        rear->next=temp;
        rear=temp;

    }
}

void deleteq()
{
    node*temp;
    temp=frontq;
    frontq=frontq->next;
    cout<<"\n Element deleted is\t"<<temp->value;
    delete(temp);
}

 void displayq()
{
    node*temp;

    cout<<"\nFRONT->\t"<<frontq->value<<"\n";

    temp=frontq->next;
    while(temp->next!=NULL)
    {
        cout<<temp->value<<"\n";
        temp=temp->next;
    }
    cout<<"\nREAR->\t"<<rear->value<<"\n";
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
        insertq();
      else if(ch==2)
        deleteq();
       else if(ch==3)
         displayq();
       else
        return 0;
    }

    return 0;
}
