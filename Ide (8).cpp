#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,c,d,arr[100001],brr[100001],crr[100001],i,j,k,n,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&q);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}	
		for(i=0;i<q;i++)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(a==c)
			{
				printf("YES\n");
				continue;
			}
			if(a<c)
			{
			if(b>=c)
			{
				k=b;
				b=d-1;
				d=k+1;
			}
			}
			if(c<a)
			{
				if(d>=a)
				{
					k=d;
					d=a-1;
					a=k+1;
				}
			}
			int z=0;
			for(j=a-1;j<b;j++)
			{
				brr[z]=arr[j];
				z++;
			}
			 z=0;
			for(j=c-1;j<d;j++)
			{
				crr[z]=arr[j];
				z++;
			}
			z=b-a+1;
			sort(brr,brr+z);
			sort(crr,crr+z);
			int flag=0;
			for(j=0;j<=z;j++)
			{
				if(brr[j]!=crr[j])
				flag++;
			    if(flag==2)
					break;
			}
			if(flag==2)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
}
				
				
				
				
				
				
				
				
				
				
				
				
					