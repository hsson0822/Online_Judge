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

int N;
int M;
vector<Edge> computer;
int parent[1001];

int getParent(int a)
{
	if (parent[a] == a) return  a;

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

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;

		computer.push_back(Edge{ a,b,w });
		computer.push_back(Edge{ b,a,w });
	}

	sort(computer.begin(), computer.end());
	
	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	int sum{};
	for (int i = 0; i < computer.size(); ++i)
	{
		if (isUnion(computer[i].a, computer[i].b))
			sum += computer[i].w;
	}
	cout << sum;
}