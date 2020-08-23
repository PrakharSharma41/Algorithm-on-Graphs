#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;
void dfs(vector<int>adj[],int u,int f,bool visit[])
{
	visit[u]=true;
	int size=adj[u].size(),i;
	for(i=0;i<size;i++)
	{
		int v=adj[u][i];
		if(v==f)
		continue;
		if(!visit[v])
		dfs(adj,v,u,visit);
	}
}

int number_of_components(vector<int > adj[],bool visit[],int n) {
  int i,res = 0;
  for(i=1;i<=n;i++)
  {
  	int z=adj[i].size();
  	visit[i]=true;
  	if(z==0)
  	res++;
//  	cout<<"z is "<<z<<"\n";
  	for(int j=0;j<z;j++)
  	{
  		int v=adj[i][j];
	   	if(!visit[v])
		{
			res++;
			dfs(adj,v,i,visit);	
		}  		
	}
  }
  return res;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int > adj[n+1];
  bool visit[n+1];
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  for(int i=1;i<=n;i++)
  visit[i]=false;
  std::cout << number_of_components(adj,visit,n);
}
