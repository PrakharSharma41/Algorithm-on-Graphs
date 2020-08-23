#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;
//6 7 
//1 2 10 
//2 3 5 
//1 3 100 
//3 5 7 
//5 4 10 
//4 3 -18 
//6 1 -1

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {

	reachable[s]=1;
	distance[s]=0;
	queue<int> q;
	int z=adj.size();
	for(int i=0;i<z;i++)
	{
		for(int u=0;u<z;u++)
		{
			int l=adj[u].size();
			for(int k=0;k<l;k++)
			{
				int v=adj[u][k];
				if(distance[u]!= std::numeric_limits<long long>::max() && distance[v] > distance[u] + cost[u][k])
				{
					distance[v]=distance[u]+cost[u][k];
					reachable[v]=1;
					if(i==z-1)
					q.push(v);
				}
			}
		}
	}
	
	vector<int> visited(adj.size());
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		visited[u]=1;
		if(u!=s)
		shortest[u]=0;
		int z=adj[u].size();
		for(int i=0;i<z;i++)
		{
			int v=adj[u][i];
			if(!visited[v])
			{
				q.push(v);
				shortest[v]=0;
				visited[v]=1;
			}
		}
	}
	distance[s]=0;
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}

