#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
typedef pair<int,int> Pair;
int distance(vector<Pair > adj[], int s, int t,int n) {
    priority_queue< Pair, vector <Pair> , greater<Pair> > pq; 
    vector<int> dist(n+1, 1e5+1); 
    pq.push(make_pair(0, s)); 
    dist[s] = 0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		for(auto x:adj[u])
		{
			int v=x.first;
			int w=x.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	} 
	if(dist[t]==(1e5+1))
	  return -1;
	return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  std::cout << distance(adj, s, t,n);
}

