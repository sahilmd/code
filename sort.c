#include<stdio.h>
void bubble_sort(int *ar,int n);
void selection_sort(int *a,int n);
void radix_sort(int *ar,int n);
void quick_sort(int *ar,int low,int high);
int partition(int *ar,int low,int high);
void merge_sort(int *ar,int low,int high);
void merge(int *ar,int low,int mid,int high); 
void show(int *ar,int n);


int main()
{
FILE *f1;
int n=0,i,ar[100],cont=1,ch,number;
f1=fopen("INPUT","r");
while((number=getw(f1))!=EOF)
{
   ar[n]=number;
   n++;
   printf("%d\t",number);
}
fclose(f1);

   printf("\n-----------------------sorting mehod---------------------------\n");
   printf("\n1.bubble sort\n2.selection sort\n3.radix sort\n4.quick sort\n5.merge sort\n");
   printf("\n enter your choice: ");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:
            bubble_sort(ar,n);
            break;
      case 2:
            selection_sort(ar,n);
            break;
      case 3:
            radix_sort(ar,n);
            break;
      case 4:
            quick_sort(ar,0,n-1);
            break;
      case 5:
            merge_sort(ar,0,n-1);
            break;
   }
   printf("\n sorted list---------------------------------------------------------------\n");
   show(ar,n);
   return 0;
}


void bubble_sort(int *ar,int n)
{
int i,j,temp;
for(i=0;i<n;i++)
{
   for(j=0;j<n-i-1;j++)
   {
      if(ar[j]>ar[j+1])
      {
          temp=ar[j];
          ar[j]=ar[j+1];
          ar[j+1]=temp;
      }
   }
}

}

void selection_sort(int *a,int n)
{
int i,pos,temp,small,j,flag=0;
for(i=0;i<n;i++)
{
   small=a[i];
   pos=i;
   for(j=i+1;j<n;j++)
   {
      if(small>a[j])
      {
         small=a[j];
         pos=j;
         flag=1;
      }
   }
   if(flag==1)
   {
      temp=a[i];
      a[i]=small;
      a[pos]=temp;
   }
}

}


void radix_sort(int *ar,int n)
{
   int bucket[11][n+1],bucket_count[11];
   int large,digit,div,index,pos;
   int i,j,k;
   digit=0;
   div=1;
   large=ar[0];
   for(int i=1;i<n;i++)
   {
      if(ar[i]>large)
      large=ar[i];
   }


   while(large>0)
   {
      digit++;
      large=large/10;
   }

   for(int pass=0;pass<digit;pass++)
   {
      for(k=0;k<10;k++)
         bucket_count[k]=0;
      for(i=0;i<n;i++)
      {
         pos=(ar[i]/div)%10;
         bucket[pos][(bucket_count[pos])++]=ar[i];
      }
      index=0;
      for(i=0;i<10;i++)
      {
         for(j=0;j<bucket_count[i];j++)
            ar[index++]=bucket[i][j];
      }
      div=div*10;
   }
}


void quick_sort(int *ar,int low,int high)
{
   int loc;
   if(low<high)
   {
      loc=partition(ar,low,high);
      quick_sort(ar,low,loc-1);
      quick_sort(ar,loc+1,high);
   }
}


int partition(int *ar,int low,int high)
{
   int loc,left,right,flag,temp;
   loc=left=low;
   right=high;
   flag=0;
   while(flag!=1)
   {
      while((ar[loc]<=ar[right]) && (loc!=right))
         right--;
      if(loc==right)
         flag=1;
      else if(ar[loc]>ar[right])
      {
         temp=ar[loc];
	 ar[loc]=ar[right];
         ar[right]=temp;
         loc=right;
      }

      if(flag!=1)
      {
         while((ar[loc]>=ar[left]) && (loc!=left))
            left++;
         if(loc==left)
            flag=1;
         else if(ar[loc]<ar[left])
         {
            temp=ar[loc];
	    ar[loc]=ar[left];
            ar[left]=temp;
            loc=left;
         }
      }
   }
   return loc;
}         
         

void merge_sort(int *ar,int low,int high)
{
   int mid;
   if(low<high)
   {
      mid=(low+high)/2;
      merge_sort(ar,low,mid);
      merge_sort(ar,mid+1,high);
      merge(ar,low,mid,high);
   }
}

void merge(int *ar,int low,int mid,int high)
{
   int i,j,k,temp[high+1];
   i=low;
   j=mid+1;
   k=low;
   while((i<=mid) && (j<=high))
   {
      if(ar[i]<ar[j])
         temp[k++]=ar[i++];
      else
         temp[k++]=ar[j++];
   }
   if(i>mid)
      while(j<high)
         temp[k++]=ar[j++];
   if(j>=high)
      while(i<=mid)
         temp[k++]=ar[i++];
   for(i=low;i<k;i++)
      ar[i]=temp[i];
}
   



void show(int *ar,int n)
{
   for(int i=0;i<n;i++)
       printf("%d\t",ar[i]);
   printf("\n");
}
