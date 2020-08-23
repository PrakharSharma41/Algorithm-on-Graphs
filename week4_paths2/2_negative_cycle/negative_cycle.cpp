#include <iostream>
#include <vector>

using namespace std;
using std::vector;
typedef pair<int,int> Pair;
int negative_cycle(vector<Pair > adj[],int s,int n,int m) {
    vector<int> dist(n+1, 1e5+1); 
	dist[s]=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int u=1;u<=n;u++)
		{
			for(auto j:adj[u])
			{
				int v=j.first;
				int w=j.second;
				if(dist[v]>dist[u]+w)
				dist[v]=dist[u]+w;
			}			
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(auto x:adj[u])
		{
			int v=x.first;
			int w=x.second;
			if(dist[v]!=(1e5)&&(dist[v]>dist[u]+w))
			return 1;			
		}
	}
    return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
	vector<Pair>adj[n+1];
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
	adj[x].push_back(make_pair(y, w)); 
  }
	std::cout << negative_cycle(adj, 1,n,m);
}
