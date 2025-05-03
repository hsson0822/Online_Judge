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
int K;

int dist[100002];
int cnt[100002];

void bfs()
{
	queue<int> Q;
	dist[N] = 0;
	cnt[N] = 1;
	Q.push(N);

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		
		for (int nx : {cur + 1, cur - 1, cur * 2})
		{
			if (nx < 0 || nx > 100000) continue;

			if (dist[nx] != -1)
			{
				if (dist[cur] + 1 == dist[nx])
					cnt[nx] += cnt[cur];
			}
			else
			{
				dist[nx] = dist[cur] + 1;
				cnt[nx] = cnt[cur];
				Q.push(nx);
			}

		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	fill(dist, dist + 100002, -1);
	bfs();

	cout << dist[K] << "\n" << cnt[K];

	return 0;
}
