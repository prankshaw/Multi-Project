#include <stdio.h>
#include <stdlib.h>
void bubbles(int n,int a[100])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
              {
                 temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
              }
        }
    }

    printf("Sorted array is...\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

}

void selections(int n,int a[100])
{
    int i,j,min,temp;
    for(j=0;j<n-1;j++)
   {
       min=j;
    for (i = j+1; i < n; i++)
    {
       if(a[i]<min)
       {
           min=i;
       }
       temp=a[j];
       a[j]=a[j];
       a[j]=temp;
    }
   }
    printf("Sorted array is...\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

}
void insertions(int n,int a[100])
{
    int i,j,k,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&temp<a[j];j--)
        {
            a[j+1]=a[j];
        }

         a[j+1]=temp;
    }

    printf("\nSorted array is...\n");
    for (k =0; k<n; k++)
    {
        printf("%d\t", a[k]);
    }
}
int main()
{
    int n,a[100],i,ch;
    printf("\nenter the no. of elements\t");
    scanf("%d",&n);
    printf("enter the array elements");
    for(i=0;i<n;i++)
        scanf("\t%d",&a[i]);
    while(1)
    {
        printf("\n choose sorting type");
        printf("\n1.bubble\t2.selection\t3.insertion\n4.quick\t5.merge\t6.shell\n7.heap");
        scanf("\t%d",&ch);
        if(ch==1)
            bubbles(n,a);
        if(ch==2)
            selections(n,a);
         if(ch==2)
            insertions(n,a);
        else
            return 0;
    }
    return 0;
}
