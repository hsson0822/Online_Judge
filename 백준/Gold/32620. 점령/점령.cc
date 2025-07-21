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

class Node
{
public:
	int num, require, acquire;

	Node(int n, int r, int a) : num(n), require(r), acquire(a) {}
};

struct cmp
{
	bool operator()(Node& a, Node& b)
	{
		return a.require > b.require;
	}
};

int N, M, r;
vector<Node> graph[500001];
bool visited[500001];
int require[500001];
int acquire[500001];

long long energy;

void bfs()
{
	priority_queue< Node, vector<Node>, cmp > PQ;
	PQ.push({r, require[r], acquire[r]});

	while (!PQ.empty())
	{
		Node cur = PQ.top();
		PQ.pop();
		
		if (!visited[cur.num] && energy >= cur.require)
		{
			//cout << "Gain : " << acquire[cur] <<endl;
			visited[cur.num] = true;
			energy += acquire[cur.num];

			for (Node n : graph[cur.num])
				PQ.push(n);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> r;

	for (int i = 1; i <= N; ++i)
		cin >> require[i];

	for (int i = 1; i <= N; ++i)
		cin >> acquire[i];

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back({b, require[b], acquire[b]});
		graph[b].push_back({a, require[a], acquire[a]});
	}

	bfs();

	cout << energy;

	return 0;
}