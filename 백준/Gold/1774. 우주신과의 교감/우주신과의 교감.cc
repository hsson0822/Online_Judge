#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
int M;
int parent[1001];
pair<int, int> pos[1001];

class Alien
{
public:
	int x;
	int y;
	double w;

	Alien(int x, int y, double w) : x(x), y(y), w(w) {}

	bool operator<(Alien& A)
	{
		return w < A.w;
	}
};

vector<Alien> graph;

int getParent(int a)
{
	if (a == parent[a])
		return a;

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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		pos[i] = { a,b };
		parent[i] = i;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j) continue;

			double w = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));				
			graph.push_back(Alien{i,j,w});
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		isUnion(a, b);
	}

	sort(graph.begin(), graph.end());
	
	double sum{};
	for (int i = 0; i < graph.size(); ++i)
	{
		if (isUnion(graph[i].x, graph[i].y))
		{
			sum += graph[i].w;
		}
	}

	cout.precision(2);
	cout <<fixed << sum;

	return 0;
}
