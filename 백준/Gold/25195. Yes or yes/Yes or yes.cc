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

int N, M, S;
vector<int> graph[100001];
bool fan[100001];

void bfs()
{
	queue<int> Q;
	Q.push(1);

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		// cout << cur << endl;

		if (graph[cur].size() == 0)
		{
			cout << "yes ";
			return;
		}

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];

			if (fan[next])
				continue;

			Q.push({next});
		}
	}

	cout << "Yes ";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
	}

	cin >> S;

	for (int i = 0; i < S; ++i)
	{
		int s;
		cin >> s;
		fan[s] = true;
	}

	if (fan[1])
	{
		cout << "Yes ";
		return 0;
	}
	bfs();

	return 0;
}