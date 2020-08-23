#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

//void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
//  //write your code here
//}     
//
//vector<int> toposort(vector<vector<int> > adj) {
//  vector<int> used(adj.size(), 0);
//  vector<int> order;
//  //write your code here
//  return order;
//}

void dfs(int u,int f,vector<int>adj[],vector<int>&mp,bool visit[])
{
	int z=adj[u].size();visit[u]=true;
	for(int i=0;i<z;i++)
	{
		int v=adj[u][i];
		if(v==f||visit[v])
		continue;
		dfs(v,u,adj,mp,visit);
		visit[v]=true;
	}
	mp.push_back(u);
}
int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<int >adj[n+1];
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
  }
  vector<int>mp;bool visit[n+1];
  for(int i=1;i<=n;i++)
  visit[i]=false;
  for(int i=1;i<=n;i++)
  {
  	if(!visit[i])
	  dfs(i,0,adj,mp,visit);
  }

  int z=mp.size();
  for(int i=z-1;i>=0;i--)
  {
  	std::cout<<mp[i]<<" ";
  }
//  vector<int> order = toposort(adj);
//  for (size_t i = 0; i < order.size(); i++) {
//    std::cout << order[i] + 1 << " ";
//  }
}
