#include <bits/stdc++>
using namespace std;

int main() {
	int s,n,h,count,flag,i;
	scanf("%d",&s);
	while(s--)
	{
	   scanf("%d",&n);
	   flag=0;
	   count=1;
	   for(i=0;i<n/2;i++)
	   {
	     scanf("%d",&h);
	     if(h!=count)
	     {
	         flag=1;
	         printf("no");
	         break;
	     }
	     count++;
	   }
	   if(flag==1)
	   break;
	   count=count-2;
	   for(i=n/2+1;i<n;i++)
	   {
	     scanf("%d",&h);
	     if(h!=count)
	     {
	         flag=1;
	         printf("no");
	         break;
	     }
	     count--;
	   }
	   if(flag!=1)
	   printf("yes\n");
	}
	
	return 0;
}
