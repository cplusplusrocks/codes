#include <stdio.h>
#include<stdlib.h>

int main(void) {
	// your code goes here
	int t,n,k,i,a[1000000],co;
	char c[1000000];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d",&n,&k);
	    scanf("%s",&c);
	    co=0;
	    a[co]=1;
	    for(i=1;i<n;i++)
	    {
	        if(c[i-1]==c[i])
	        a[co]++;
	        else
	        a[++co];
	    }
	    for(i=0;i<co;i++)
	    printf("%d ",a[i]);
	}
	return 0;
}

