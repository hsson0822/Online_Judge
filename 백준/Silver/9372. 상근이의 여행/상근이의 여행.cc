#include <iostream>
#include <vector>

using namespace std;

class Edge
{
public:
	int a;
	int b;

	Edge(int a, int b) : a(a), b(b) {}
};

int N;
int M;
vector<Edge> plane;
int parent[1001];

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

	if (pa < pb)
		parent[pb] = pa;
	else
		parent[pa] = pb;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{
		cin >> N >> M;

		for (int i = 0; i < M; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
			plane.push_back(Edge{ a,b });
		}

		for (int i = 1; i <= N; ++i)
			parent[i] = i;

		int cnt{};
		for (int i = 0; i < plane.size(); ++i)
		{
			if(isUnion(plane[i].a, plane[i].b))
				++cnt;
		}
		cout << cnt << "\n";
	}

	
	return 0;
}