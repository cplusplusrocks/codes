#include<bits/stdc++.h>
using namespace std;
 int x,y,num;
 long long int sum;
 int arr[100001][1001],prime[1000000],prime_count=1,result[1001][78500],beg=0;
 vector<int> least_prime(1000003, 0);
void leastPrimeFactor(int n)
{
    
    least_prime[1] = 1;
 
    for (int i = 2; i <= n; i++)
    {
       
        if (least_prime[i] == 0)
        {
           
            least_prime[i] = i;
 
            
            for (int j = 2*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   {least_prime[j] = i;}
        }
    }
    for(int i=2;i<n;i++)
    {
        if(i==least_prime[i])
        {prime[i]=prime_count;
        result[0][prime_count]=i;
       // printf("%d,",result[0][prime_count]); 
        prime_count++;
            
        }
    }
 
}
 
void generatePrimeFactors(int N)
{
   
 
   int temp=N;
 
    int curr = least_prime[N]; 
   
    int cnt = 1;   
    
 
    
    while (N > 1)
    {
        result[beg][prime[curr]]++;
        if(curr<=1000)
        arr[num][curr]=cnt;
        else
        arr[num][0]=curr;
        N /= least_prime[N];
 
       
      // printf("%d,,,,,,\n",arr[num][1]);
        if (curr == least_prime[N])
        {
            cnt++;
            continue;
        }
      //  printf("%d %d %d,",N,curr,cnt);
       // if(curr>=x&&curr<=y)
      //  sum=sum+cnt;
        
        curr = least_prime[N];
       cnt = 1;
     // cnt++;
    }
   //arr[num][0]=cnt;
}
 
 
int main()
{
    int m=1000002;
    
   
    int arrr[100002],i,n,q,j,l,r,max,k,flag;
   scanf("%d",&n);
 /*for(i=0;i<100000;i++)
  {
      if(i<10000)
      arrr[i]=1000000;
      else
      arrr[i]=999983;
      
  }*/
 // arrr[0]=3153;
    for(i=0;i<100000;i++)
    {
        for(j=0;j<1001;j++)
        arr[i][j]=0;
    }
 /*   for(i=0;i<1001;i++)
    {
        for(j=0;j<78500;j++)
        result[i][j]=1;
    }*/
  // n=100000;
    leastPrimeFactor(m);
    for(i=0;i<n;i++)
    {
        if(i%100==0)
        beg++;
       scanf("%d",&arrr[i]);
    num=i;
    generatePrimeFactors(arrr[i]); 
    //if(i==0)
   // printf("%d\n",arr[i][1]);
    }
     
    for(i=0;i<n;i++)
    {
        
        for(j=2;j<1001;j++)
        arr[i][j]=arr[i][j-1]+arr[i][j];
    }
    
    for(i=1;i<=beg;i++)
    {
        
        for(j=2;j<78500;j++)
        result[i][j]=result[i][j-1]+result[i][j];
    }
     for(i=2;i<=beg;i++)
    {
        
        for(j=1;j<78500;j++)
        result[i][j]=result[i-1][j]+result[i][j];
    }
   
    
    
    scanf("%d",&q);
   
    for(j=0;j<q;j++)
    {
    sum=0;
    k=0;
    
    scanf("%d %d %d %d",&l,&r,&x,&y);
    
   int xx=upper_bound(result[0],result[0]+prime_count,x)-result[0];
   int xxl=lower_bound(result[0],result[0]+prime_count,x)-result[0];
   int yy=upper_bound(result[0],result[0]+prime_count,y)-result[0]-1;
   if(xx!=xxl)
   xx=xx-1;
 //  printf("%d\n",xxl);
   l=l-1;
   int rr=r;
   if(r!=1)
   r=r-1;
    max=l/100+1;
    flag=r/100+1;
   
    
    
    sum=result[flag][yy];
    
    if(xx>1)
    {
        sum=sum-result[flag][xx-1];
        k++;
    }
    if(max>1)
    {
        sum=sum-result[max-1][yy];
        k++;
    }
    if(k==2)
    sum=sum+result[max-1][xx-1];
    if(l%100!=0)
    max--;
    if(r%100!=0)
    flag--;
    max=max*100;
    flag=flag*100;
   
   for(i=max;i<l;i++)
    {
      if(y>1000)
      {
          k=1000;
          if(arr[i][0]>=x&&arr[i][0]<=y)
          sum=sum-1;
      }
      else
      k=y;
      if(x<1000&&x>1)
      sum=sum-(arr[i][k]-arr[i][x-1]);
      else if(x==1)
      sum=sum-arr[i][k];
    }
   
   if(flag<r)
     flag=flag+100;
     // printf("%d,",flag);
     if(rr==1)
     r--;
   for(i=r+1;i<flag;i++)
    {
      if(y>1000)
      {
          k=1000;
          if(arr[i][0]>=x&&arr[i][0]<=y)
          sum=sum-1;
      }
      else
      k=y;
      if(x<1000&&x>1)
      sum=sum-(arr[i][k]-arr[i][x-1]);
      else if(x==1)
      sum=sum-arr[i][k];
    }
    
  
       
    
     
    //printf("\n");}
    printf("%lld\n",sum);
        
    }
   
  /*  for(i=0;i<50;i++)
    {
        for(j=0;j<1000;j++)
        printf("%d,",result[i][j]);
        printf("\n");
    }*/
   // for(i=0;i<20;i++)
   // printf("%d,",sum);
  
  
    return 0;
    
}