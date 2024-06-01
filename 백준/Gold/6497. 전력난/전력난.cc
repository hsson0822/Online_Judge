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

int M;
int N;
vector<Edge> village;
int parent[200001];

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

	while (true)
	{
		cin >> M >> N;

		if (M == 0 && N == 0) break;

		int now{};
		for (int i = 0; i < N; ++i)
		{
			int a;
			int b;
			int w;
			cin >> a >> b >> w;
			now += w;
			village.push_back(Edge{ a,b,w });
		}

		for (int i = 0; i < M; ++i)
			parent[i] = i;

		sort(village.begin(), village.end());

		int ans{};
		for (int i = 0; i < N; ++i)
		{
			if (isUnion(village[i].a, village[i].b))
				ans += village[i].w;
		}

		cout << now - ans<< endl;
		village.clear();
	}

	return 0;
}