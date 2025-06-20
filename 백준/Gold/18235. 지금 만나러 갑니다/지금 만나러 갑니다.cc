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

int N, A, B;
int point[500001];
int answer = -1;

void bfs()
{
	queue<pair<int,int>> Q;
	Q.push({ A,0 });
	Q.push({ B,0 });

	while (!Q.empty())
	{
		int cur = Q.front().first;
		int day = Q.front().second;
		Q.pop();

		int dist = pow(2, day);
		int next = cur + dist;
		
		if (next <= N)
		{
			if (point[next] == day + 1)
			{
				answer = day + 1;
				break;
			}
			else
			{
				point[next] = day + 1;
				Q.push({ next,day + 1 });
			}
		}

		next = cur - dist;
		if (next > 0)
		{
			if (point[next] == day + 1)
			{
				answer = day + 1;
				break;
			}
			else
			{
				point[next] = day + 1;
				Q.push({ next,day + 1 });
			}
		}
		
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> A >> B;

	bfs();

	cout << answer;

	return 0;
}
