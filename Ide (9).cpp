#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t,arr[500001],k,n,ele;
    unsigned int i,b,c;
	
	scanf("%d",&t);
	while(t--)
	{
	  
	  	scanf("%d",&n);
	  	
	  	for(i=4294967290;i>0;i--)
	  	{
	  	    if(i%(n-2)==0)
	  	    break;
	  	    
	  	}
	  	b=i/(n-2);
	  	c=4294967295-b*(n-2);
	  	c=c-3;
	  	for(i=0;i<n-2;i++)
	  	printf("%u ",b);
	   printf("%u 1 \n",c);
	  	
	  
	  
	 
	}
	return 0;
}
