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

int hope[100001];
bool isTeam[100001];
bool isVisited[100001];
int cnt;

void dfs(int start)
{
	isVisited[start] = true;
	
	int next = hope[start];

	if (!isVisited[next])
	{
		dfs(next);
	}
	else if (!isTeam[next])
	{
		for (int i = next; i != start; i = hope[i])
			++cnt;
		++cnt;
	}
	isTeam[start] = true;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		int N;
		cin >> N;

		

		for (int i = 1; i <= N; ++i)
			cin >> hope[i];

		for (int i = 1; i <= N; ++i)
		{
			if(!isTeam[i])
				dfs(i);
		}

		cout << N - cnt << "\n";
		cnt = 0;

		memset(isTeam, false, sizeof(isTeam));
		memset(isVisited, false, sizeof(isVisited));
	}

	return 0;
}
