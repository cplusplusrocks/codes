#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n,k,i,j,f,e;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d",&n,&k);
	    int a[n+1][k];
	      for(i=0;i<n+1;i++)
	        for(j=0;j<k;j++)
    	    a[i][j]=0;
    	   
	    for(i=0;i<n;i++)
	    {   
	        scanf("%d",&f);
	        for(j=0;j<f;j++)
    	    {
    	        scanf("%d",&e);
    	        a[i][e-1]=1;
    	        a[n][e-1]++;
    	    }
	    }
	    for(i=0;i<=n;i++)
	       { for(j=0;j<k;j++)
    	    printf("%d",a[i][j]);
    	    printf("\n");
	       }
	   for(i=0;i<k;i++)
	   if(a[n][i]==0)
	   {
	       printf("sad\n");
	       return 0;
	   }
    	}
	
	return 0;
}
