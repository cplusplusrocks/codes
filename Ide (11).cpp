#include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t,n,k,l[2500],i,a[2501][2501],e,j,m,flag;
	scanf("%d",&t);
	
	while(t--)
	{
	   scanf("%d %d",&n,&k);
	   for(i=0;i<2501;i++)
	   {
	       for(j=0;j<=2500;j++)
	       a[i][j]=0;
	   }
	   for(i=0;i<n;i++)
	   for(i=0;i<n;i++)
	   {
	       scanf("%d",&l[i]);
	       for(j=0;j<l[i];j++)
	       {
	           scanf("%d",&e);
	           a[i][e]=1;
	       }
	   }
	  
	   int count=0;
	   for(i=0;i<n;i++)
	   {
	       for(j=i+1;j<n;j++)
	       {
	           if(l[i]+l[j>=k])
	           {flag=1;
	               for(m=1;m<=k;m++)
	               {
	                   if(a[i][m]+a[j][m]<1)
	                   {
	                       flag=0;
	                       break;
	                   }
	               }
	               if(flag==1)
	               count++;
	           }
	       }
	   }
	   printf("%d\n",count);
	}
	return 0;
}
 