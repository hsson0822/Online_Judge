#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int P;
int W;

int C;
int V;

class Edge
{
public:
	int a;
	int b;
	int w;

	Edge(int a, int b, int w) : a(a), b(b), w(w) {}

	bool operator<(Edge& edge)
	{
		return w > edge.w;
	}
};

vector<Edge> road;
int parent[1001];
int answer = INT_MAX;

int getParent(int a)
{
	if (parent[a] == a) return a;

	return parent[a] = getParent(parent[a]);
}

void Union(int a, int b)
{
	int pa = getParent(a);
	int pb = getParent(b);

	parent[pb] = pa;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> P >> W;
	cin >> C >> V;


	for (int i = 0; i < W; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;

		road.push_back({ a,b,w });
	}

	for (int i = 0; i <= P; ++i)
		parent[i] = i;

	sort(road.begin(), road.end());

	for (int i = 0; i < road.size(); ++i)
	{
		if (getParent(road[i].a) != getParent(road[i].b))
		{
			Union(road[i].a, road[i].b);
			answer = min(answer, road[i].w);

			if (getParent(C) == getParent(V))
			{
				cout << answer;
				break;
			}
		}

	}
	return 0;
}
