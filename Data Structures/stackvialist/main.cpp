#include <iostream>

using namespace std;

struct node
{
    int value;
    node*next;
}*top=NULL;

void inserts()
{
    intv;
    node*temp;

    cout<<"\n Enter the value you want to insert\t";
    cin>>v;

    temp->value=v;
    temp->next=NULL;

    if(top==NULL)
    {

       top->value=v;
       top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

void deletes()
{
    node*temp;
    temp=top;
    top=top->next;
    cout<<"\n Element deleted is\t"<<temp->value;
    delete(temp);
}

 void displays()
{
    node*temp;

    cout<<"\nTOP->\t"<<top->value<<"\n";

    temp=top->next;
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
        inserts();
      else if(ch==2)
        deletes();
       else if(ch==3)
         displays();
       else
        return 0;
    }

    return 0;
}
