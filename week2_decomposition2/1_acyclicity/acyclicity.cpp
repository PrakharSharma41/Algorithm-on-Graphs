#include <iostream>
#include <vector>
#include<stack>
#include<algorithm>
//using std::vector;
//using std::pair;
#include<bits/stdc++.h>
using namespace std;
//  res is mandatory for directed graph but not for undirected graph
bool dfs(int node,vector<int>adj[],bool visit[],bool res[])
{
	if(!visit[node])
	{
		visit[node]=true;
		res[node]=true;
	}
	int z=adj[node].size();
	for(int i=0;i<z;i++)
	{
		int it=adj[node][i];
		if(!visit[it]&&dfs(it,adj,visit,res))
		return true;
		else if(res[it])
		return true;
	}
	res[node]=false;
	return false;
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
  int k=0;bool visit[n+1],res[n+1];
  for(int i=0;i<=n;i++)
  {
  	visit[i]=false;
  	res[i]=false;
  }
  int x=0;
  for(int i=1;i<=n;i++)
  {
  	if(!visit[i])
  	{
  		if(dfs(i,adj,visit,res))
		{
			x=1;break;
		}
	}
  }
  std::cout << x;
}

