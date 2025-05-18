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
int bamboo[501][501];
int dp[501][501];

int dX[]{ 1,0,-1,0 };
int dY[]{ 0, 1,0,-1 };


int dfs(int x, int y)
{
    if (dp[x][y] != 0) return dp[x][y];
    
	int len = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dX[i];
		int ny = y + dY[i];

		if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
		if (bamboo[x][y] >= bamboo[nx][ny]) continue;


		if (dp[nx][ny] == 0)
			len = max(len,dfs(nx, ny)+1);
		else
			len = max(len,dp[nx][ny]+1);

	}

	dp[x][y] = len;

	return len;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> bamboo[i][j];

	int answer{};
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			answer = max(answer,dfs(i, j));
		}
	}
	

	cout << answer;

	return 0;
}
