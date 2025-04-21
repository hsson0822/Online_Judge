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

int N = 12;
int M = 6;

char field[12][6];
bool visited[12][6];

int dX[]{ 1,0,-1,0 };
int dY[]{ 0,1,0,-1 };

bool erase(int i, int j, char ch)
{
	queue<pair<int, int>> Q;
	stack<pair<int, int>> sta;
	Q.push({i,j});
	sta.push({ i,j });
	visited[i][j] = true;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dX[i];
			int ny = y + dY[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (field[nx][ny] != ch) continue;
			if (visited[nx][ny]) continue;

			Q.push({ nx,ny });
			visited[nx][ny] = true;
			sta.push({ nx,ny });
		}
	}

	if (sta.size() >= 4)
	{
		while (!sta.empty())
		{
			int x = sta.top().first;
			int y = sta.top().second;
			sta.pop();
			field[x][y] = '.';
		}
		return true;
	}

	return false;
}

void down()
{
	for (int j = 0; j < M; ++j)
	{
		queue<char> Q;
		for (int i = N - 1; i >= 0; --i)
		{
			if (field[i][j] != '.')
			{
				Q.push(field[i][j]);
				field[i][j] = '.';
			}
		}
		
		int i = N - 1;
		while (!Q.empty())
		{
			field[i][j] = Q.front();
			--i;
			Q.pop();
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> field[i][j];
		}
	}

	int answer{};

	while (true)
	{
		int cnt{};
		
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				bool flag = false;
				if (visited[i][j] == false && field[i][j] != '.')
					flag = erase(i,j, field[i][j] );

				if (flag)
					++cnt;
			}
		}

		down();

		if (cnt >= 1)
			++answer;
		else if (cnt == 0)
			break;


	}

	cout << answer;

	return 0;
}
