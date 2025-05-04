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

int N;
int M;
int T;

class Edge
{
public:
	int a;
	int b;
	int w;

	Edge(int a, int b, int w) : a(a),b(b),w(w){}

	bool operator<(Edge& edge)
	{
		return w < edge.w;
	}
};

vector <Edge> country;
int parent[10001];

int getParent(int a)
{
	if (a == parent[a]) return a;

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

	cin >> N >> M >> T;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;

		country.push_back({ a,b,w });
	}

	sort(country.begin(), country.end());

	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	int sum{};
	int cnt{};
	for (int i = 0; i < country.size(); ++i)
	{
		if (isUnion(country[i].a, country[i].b))
		{
			sum += country[i].w + cnt * T;
			++cnt;
		}
	}

	cout << sum;

	return 0;
}
