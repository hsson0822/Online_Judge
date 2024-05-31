#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:

	int node[2];
	int upDown;

	Edge() {}

	Edge(int a, int b, int u)
	{
		node[0] = a;
		node[1] = b;

		upDown = u;
	}

	bool operator<(Edge& edge)
	{
		return upDown < edge.upDown;
	}

	bool operator> (Edge& edge)
	{
		return upDown > edge.upDown;
	}

};

int N;
int M;

vector<Edge> route;
int parent[1001];

int getParent(int a)
{
	if (parent[a] == a) return a;

	return parent[a] = getParent(parent[a]);
}

bool isUnion(int a , int b)
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

	cin >> N >> M;
	int start;

	int a;
	int b;
	int u;
	cin >> a >> b >> u;
	start = u == 1 ? 0 : 1;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int u;
		cin >> a >> b >> u;

		route.push_back(Edge(a, b, u));
		route.push_back(Edge(b, a, u));
	}

	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	sort(route.begin(), route.end());

	int up{};
	for (int i = 0; i < route.size(); ++i)
	{
		if (isUnion(route[i].node[0], route[i].node[1]))
			up += route[i].upDown == 1 ? 0 : 1;
	}

	int down{};
	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	for (int i = route.size() - 1; i >= 0; --i)
	{
		if (isUnion(route[i].node[0], route[i].node[1]))
			down += route[i].upDown == 1 ? 0 : 1;
	}

	cout << pow(up + start, 2) - pow(down + start, 2);

	return 0;
}