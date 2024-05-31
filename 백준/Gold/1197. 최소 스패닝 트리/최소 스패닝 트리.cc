#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
	int a;
	int b;
	int w;

	Edge(int a, int b, int w) : a(a), b(b), w(w) {}

	bool operator<(Edge& edge)
	{
		return w < edge.w;
	}
};

int V;
int E;
vector<Edge> graph;
int parent[10001];

int getParent(int a)
{
	if (parent[a] == a) return a;

	return parent[a] = getParent(parent[a]);
}

bool isUnion(int a, int b)
{
	int pa = getParent(a);
	int pb = getParent(b);

	if (pa == pb) return false;

	parent[pa] = pb;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		graph.push_back(Edge{ a,b,w });
	}

	sort(graph.begin(), graph.end());

	for(int i =1 ; i <= V ; ++i)
		parent[i] = i;

	int sum{};
	for (int i = 0; i < graph.size(); ++i)
	{
		if (isUnion(graph[i].a, graph[i].b))
			sum += graph[i].w;
	}

	cout << sum;
	return 0;
}