#include <bits/stdc++.h>
using namespace std;
void build(int ss , int se , int i)
{
	if(ss == se){
		t[i] = a[ss];
		return ; 
	}
	int mid = (ss+se)/2;
	build(ss , mid , 2*i+1);
	build(mid+1 , se , 2*i+2); 
	t[i] = t[2*i+1] + t[2*i+2]; 
}
void get(int ss ,int se ,int qs , int qe , int i)
{
	if(lazy[i] > 0) propagate(ss , se , i);
	if(qs > se || qe < ss) return 0;
	if(qs  ss && qe > =se) return t[i];
	int mid = (ss+se)/2;
	return get(ss , mid ,  qs , qe , 2*i+1) + 
		get(mid+1, se , qs , qe , 2*i+2); 
}

void propagate(int ss , int se , int i)
{
	lazy[i] = lazy[i] % 10 ;
	tree[i].sum =0 ;  
	for(int j =0  ; j < 10 ; j++){
		cnt1[j] = tree[i].cnt[(j - lazy[i] + 10) % 10]; 
	}
	for(int j =0 ; j < 10 ; j++){
		tree[i].cnt[j] = cnt1[j]; 
		tree[i].sum+= cnt1[j] * j ; 
	}
	if(ss != se)
	{
		lazy[2*i+1]+= lazy[i];
		lazy[2*i+2]+= lazy[i]; 
	}
	lazy[i] = 0 ; 
}

void update(int ss , int se  ,int qs, int qe , int i,int val)
{
	if(lazy[i] > 0 ) propagate(ss , se , i ); 
	if(qs > se || qe < ss) return ; 
	if(qs <= ss && qe>= se) 
	{
		lazy[i]+= val ;
		propagate(ss , se , i);
		return ;  
	}
	int mid = (ss + se)/2;
	update(ss , mid ,qs , qe , 2*i+1,val);
	update(mid+1 , se , qs, qe , 2*i+2,val);
	t[i] = t[2*i+1]+t[2*i+2]; 
}

int main() {
	// your code goes here
	int t,n,i,j,a[202],x1,x2,y1,y2,temp,fin[51][51],k,final[51][51];
	//char ;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=1;i<=50;i++){
	    for(j=1;j<=50;j++)
	    final[i][j]=0;
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
	        for(i=1;i<=50;i++){
	    for(j=1;j<=50;j++)
	    fin[i][j]=0;
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
	        else
	        {
	            for(j=x1-1;j>=1;j--)
	            {
	                temp=fin[j+1][y1]+1;
	                if(temp>fin[j][x1])
	                fin[j][x1]=temp;
	            }
	            for(j=x2+1;j<=50;j++)
	            {
	                
	                temp=fin[j-1][y2]+1;
	                if(temp>fin[j][y1])
	                fin[j][y1]=temp;
	            }
	            for(j=y1-1;j>=1;j--)
	            for(k=1;k<=50;k++)
	            {
	                temp=fin[k][j+1]+1;
	                if(temp>fin[k][j])
	                fin[k][j]=temp;
	            }
	            for(j=y1+1;j<=50;j++)
	            for(k=1;k<=50;k++)
	            {
	                temp=fin[k][j-1]+1;
	                if(temp>fin[k][j])
	                fin[k][j]=temp;
	            }
	        }
	        for(i=1;i<=50;i++){
	        for(j=1;j<=50;j++) 
	        {
	            if(fin[i][j]>final[i][j])
	            final[i][j]=fin[i][j];
	        }}
	    }
	    int min=final[1][1];
	    for(i=1;i<=50;i++){
	    for(j=1;j<=50;j++)
	    {
	        if(final[i][j]<min)
	        min=final[i][j];
	       
	    }
	    }
	 printf("%d",min);

	}
	return 0;
}
