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

	Edge(int a, int b, int w) :a(a), b(b), w(w) {}

	bool operator< (Edge& edge)
	{
		return w < edge.w;
	}
};

int N;
int M;
vector<Edge> village;
int parent[100001];

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

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		village.push_back(Edge{ a,b,w });
	}

	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	sort(village.begin(), village.end());

	int answer{};
	int last{};
	for (int i = 0; i < village.size() ; ++i)
	{
		if (isUnion(village[i].a, village[i].b))
		{
			answer += village[i].w;
			if(last < village[i].w)
				last = village[i].w;
		}
	}
	cout << answer - last;
	
	return 0;
}