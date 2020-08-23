#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;
using std::pair;

void dfs(int node,vector<int>adj[],stack<int>&s,bool visit[])
{
	visit[node]=true;
	for(auto it:adj[node])
	{
		if(!visit[it])
			dfs(it,adj,s,visit);
	}	
	s.push(node);
}
void rdfs(int node,vector<int>adj2[],bool visit[])
{
	visit[node]=true;
	for(auto it:adj2[node])
	{
		if(!visit[it])
		rdfs(it,adj2,visit);
	}
}
int main() {
  size_t n, m,i;
  std::cin >> n >> m;
	vector<int> adj[n+1],adj2[n+1];bool visit[n+1];stack<int>s;
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj2[y].push_back(x);
  }
  
  for(i=0;i<=n;i++)
  visit[i]=false;
  for(i=1;i<=n;i++)
  if(!visit[i])
  dfs(i,adj,s,visit);
  for(i=0;i<=n;i++)
  visit[i]=false;
  int count=0;
  while(!s.empty())
  {
  	int x=s.top();
  	s.pop();
//  	cout<<x<<"\n";
  	if(!visit[x])
  	{
  		count++;
  		rdfs(x,adj2,visit);
	}
  }
  cout<<count<<"\n";
//  std::cout << number_of_strongly_connected_components(adj);
}
