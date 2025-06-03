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

class Edge
{
public:
	int a;
	int b;
	int w;
	Edge(int a, int b, int w) :a(a) , b(b), w(w) {}
	bool operator<(Edge& edge)
	{
		return w < edge.w;
	}
};

int N;
int M;
int K;
vector<Edge> elec;
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

	parent[pb] = pa;
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i <= N; ++i)
		parent[i] = i;

	for (int i = 0; i < K; ++i)
	{
		int a;
		cin >> a;
		elec.push_back({ 0,a,0 });
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		elec.push_back({ a,b,w });
	}

	sort(elec.begin(), elec.end());

	int sum{};
	for (int i = 0; i < elec.size(); ++i)
	{
		if (isUnion(elec[i].a, elec[i].b))
			sum += elec[i].w;
	}

	cout << sum;

	return 0;
}
