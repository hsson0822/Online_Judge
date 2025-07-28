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

int charToNum(char ch)
{
	if(isupper(ch))
	return ch - 'A' + 27;
	else if (islower(ch))
	return ch - 'a' + 1;
}

class Edge
{
public:
	int a, b, w;

	Edge(int a, int b, int w) : a(a), b(b), w(w) {}

	bool operator<(Edge &e)
	{
		return w < e.w;
	}
};

vector<Edge> graph;
int parent[51];
int total{};

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

	if (pa == pb)
		return false;

	parent[pb] = pa;
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	// cout << charToNum('a');

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{

			char ch;
			cin >> ch;

			if(ch == '0') continue;

			int len = charToNum(ch);
			//cout << ch << " : " << len<<endl;
			total += len;

			if (i == j)
				continue;

			graph.push_back({i, j, len});
			graph.push_back({j, i, len});
		}
	}

	for (int i = 0; i <= N; ++i)
		parent[i] = i;

	sort(graph.begin(), graph.end());
	int able{};

	for (int i = 0; i < graph.size(); ++i)
	{
		if (isUnion(graph[i].a, graph[i].b))
			able += graph[i].w;
	}

	for(int i = 1 ; i <= N ; ++i)
	{
		getParent(i);
	}

	int p = parent[1];
	int cnt = 1;
	for(int i = 2 ; i <=N ;++i)
	{
		if( p == parent[i])
			++cnt;
	}

	if(cnt == N)
		cout << (total - able);
	else
		cout << -1;
	//cout << "TOTAL : " << total << endl;
	//cout << "ABLE : " << able << endl;

	return 0;
}