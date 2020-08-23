#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::vector;
using std::queue;

int find(vector<int>adj[], int s, int t,int n) {
	queue<int>q;
	int i,dist[n+1];
	bool visit[n+1];
	for(i=1;i<=n;i++)
	{
		visit[i]=false;
		dist[i]=1000001;
	}
	dist[s]=0;visit[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int v,u=q.front();
		q.pop();
		int z=adj[u].size();
//		cout<<"u is "<<u<<"\n";
//		cout<<"z is "<<z<<"\n";
		for(i=0;i<z;i++)
		{
			v=adj[u][i];
			if(!visit[v])
			{
				visit[v]=true;
				dist[v]=dist[u]+1;
//				cout<<"v is "<<v<<"\n";
//				cout<<"dist[v] is "<<dist[v]<<"\n";
				q.push(v);
			}
			if(v==t)
			return dist[v];
		}
	}
	
    return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
	vector<int>adj[n+1];
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int s, t;
  std::cin >> s >> t;
  std::cout << find(adj, s, t,n);
}
