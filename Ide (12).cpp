#include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	long long int u,v,num1,num2,d,s,k;
	scanf("%d",&t);
	while(t--)
	{
	   scanf("%lld %lld",&u,&v); 
	   num1=(v+1)*(v+1)/2-(v+1)/2+1;
	   d=2+v;
	   s=(2*d-3)*(u+1);
	   num2=((u+1)*(u+1)+s)/2+num1+1-d;
	   
	   printf("%lld\n",num2);
	}
	return 0;
}