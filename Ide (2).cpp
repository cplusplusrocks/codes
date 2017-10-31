#include <bits/stdc++>
using namespace std;
// syntax for priority queue
// for popping minimum element first
priority_queue<int , vector < int > , greater<int> > q;

typedef pair<int, int> pp ; 
pp p1; 
this is same as
pair<int,int> p1;

//queue used in dijkstra
priority_queue<pp , std::vector<pp>, greater<pp> > q;

// vis[] -> visited array
// v[node] -> stores pair<adjacent node, edge> 

void dij(int source)
{
  q.push(make_pair(0,source));
  // memset dis array -> inf; 
  dis[source] = 0 ;
  while(!q.empty())
  {
    pp tmp = q.top(); 
    int node = tmp.s;
    int wt = tmp.f; 
    q.pop();

    if(vis[node]) continue; 
    vis[node] =1;

    for(int i =0 ;i < v[node].size(); i++)
    {
      int child = v[node][i].first;
      int weightofedge = v[node][i].second; 
      if(dis[child] > dis[node] + weightofedge )
      {
        dis[child] = dis[node] + weightofedge;
        parent[child] = node; 
        q.push(mp(dis[child] ,child)); 
      }
    }
  }
}
void solve(int dest ,int source)
{
  int node = dest ; 

  while(parent[node] != source){
    cout << node << " " ; 
    node = parent[node] ; 
  }
}

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
