#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using namespace std;

struct node{
	int parent,rank,x,y;
	node(int a,int b,int c=-1,int d=0){
		x = a;
	    y = b;
	    parent = c;
	    rank = d;
	}
	
};

struct edge{
	int u,v;
	double weight;
	edge(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};
bool cmp(edge a,edge b){
	return a.weight<b.weight;
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int find(int i,vector<node>&nodes)
{
	if(i!=nodes[i].parent){
		nodes[i].parent = find(nodes[i].parent, nodes);
	}
	return nodes[i].parent;
}
int unions(int u,int v,vector<node>&nodes)
{
	int x=find(u,nodes),y=find(v,nodes);
	if(x!=y)
	{
		if(nodes[x].rank>nodes[y].rank)
		{
			nodes[y].parent=x;
		}
		else if(nodes[x].rank<nodes[y].rank)
		{
			nodes[x].parent=y;
		}
		else
		{
			nodes[x].parent=y;
			nodes[y].rank++;
		}
	}
}
double minimum_distance(vector<int> x, vector<int> y) {
	double result = 0.;
	int n=x.size();
	vector<node>nodes;
	for(int i=0;i<n;i++)
	{
		nodes.push_back(node(x[i],y[i],i));
	}
	vector<edge>edges;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			edges.push_back(edge(i,j, weight(x[i], y[i], x[j], y[j])));
		}
	}
	sort(edges.begin(),edges.end(),cmp);
	int z=edges.size(),u,v;
	for(int i=0;i<z;i++)
	{
		u=edges[i].u;
		v=edges[i].v;
		if(find(u,nodes)!=find(v,nodes))
		{
			result+=edges[i].weight;
			unions(u,v,nodes);
		}
	}
	return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
