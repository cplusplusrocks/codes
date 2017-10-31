#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n,i,j,a[202],x1,x2,y1,y2,temp,fin[51][51],k;
	//char ;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=1;i<=50;i++){
	    for(j=1;j<=50;j++)
	    fin[i][j]=0;
	    }
	    for(i=1;i<=4*n;i++)
	    {
	        scanf("%d",&a[i]);
	    }
	     for(i=1;i<=n;i++)
	    {
	        x1=a[4*i-3];
	        y1=a[4*i-2];
	        x2=a[4*i-1];
	        y2=a[4*i];
	        if(y2-y1<0)
	        {
	            temp=y2;
	            y2=y1;
	            y1=temp;
	        }
	        if(x2-x1<0)
	        {
	            temp=x2;
	            x2=x1;
	            x1=temp;
	       
	        }
	        if(y2-y1>0)
	        {
	            for(j=y1-1;j>=1;j--)
	            {
	                temp=fin[x1][j+1]+1;
	                if(temp>fin[x1][j])
	                fin[x1][j]=temp;
	            }
	            for(j=y2+1;j<=50;j++)
	            {
	                
	                temp=fin[x1][j-1]+1;
	                if(temp>fin[x1][j])
	                fin[x1][j]=temp;
	            }
	            for(j=x1-1;j>=1;j--)
	            for(k=1;k<=50;k++)
	            {
	                temp=fin[j+1][k]+1;
	                if(temp>fin[j][k])
	                fin[j][k]=temp;
	            }
	            for(j=x1+1;j<=50;j++)
	            for(k=1;k<=50;k++)
	            {
	                temp=fin[j-1][k]+1;
	                if(temp>fin[j][k])
	                fin[j][k]=temp;
	            }
	            
	        }
	    }
	    
	    for(i=1;i<=50;i++){
	    for(j=1;j<=50;j++)
	    {
	        printf("%d,",fin[i][j]);
	    }
	    printf("\n");
	    }
	 

	}
	return 0;
}