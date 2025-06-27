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
int buildTime[501];
int timer[501];
int parentCnt[501];
vector<int> graph[501];

queue<int> Q;

void bfs()
{
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];

			timer[next] = max(timer[next], timer[cur] + buildTime[next]);

			--parentCnt[next];

			if (parentCnt[next] == 0)
				Q.push(next);
			
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int t;
		cin >> t;
		buildTime[i] = t;

		int parent;
		cin >> parent;

		while (parent != -1)
		{
			++parentCnt[i];
			graph[parent].push_back(i);
			cin >> parent;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (parentCnt[i] == 0)
		{
			Q.push(i);
			timer[i] = buildTime[i];
		}
	}
	
	bfs();

	for (int i = 1; i <= N; ++i)
	{
		cout << timer[i] << "\n";
	}

	return 0;
}