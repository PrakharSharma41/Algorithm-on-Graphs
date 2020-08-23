#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;


int reach(vector<int > adj[], int x, int y,int f) {
//	cout<<"here\n";
	int z=adj[y].size();
	for(int i=0;i<z;i++)
	{
		int v=adj[y][i];
		if(v==x)
		return 1;
		if(v==f)
		continue;
		if(reach(adj,x,v,y)==1)
		return 1;
	}
	return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<int> adj[n+1];
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x, y,0);
}
