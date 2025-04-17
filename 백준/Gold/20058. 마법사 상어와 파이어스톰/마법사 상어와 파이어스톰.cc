#include <iostream>
#include <map>
#include <unordered_map>
#include <cstring>
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

using namespace std;

int N;
int Q;
int ice[65][65];
int dX[]{ 1,0,-1,0 };
int dY[]{ 0,1,0,-1 };


void roll(int r, int c, int size)
{
	int** temp = new int*[size];
	
	for (int i = 0; i < size; i++)
		temp[i] = new int[size];


	for (int i = r; i < r+size; ++i)
	{
		for (int j = c; j < c+size; ++j)
		{
			temp[j-c][size-i-1+r] = ice[i][j];
		}
	}

	for (int i = r; i < r+size; ++i)
	{
		for (int j = c; j < c + size; ++j)
		{
			ice[i][j] = temp[i-r][j-c];
		}
	}
}

void select(int k)
{
	int size = pow(2, k);

	for (int i = 0; i < N; i += size)
	{
		for (int j = 0; j < N; j += size)
		{
			roll(i, j, size);
		}
	}
}

void meltIce()
{
	bool temp[65][65];
	memset(temp, false, sizeof(temp));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int cnt{};

			for(int k = 0 ; k < 4 ; ++k)
			{
				int nx = i + dX[k];
				int ny = j + dY[k];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				
				if (ice[nx][ny] > 0)
					++cnt;
			}

			if (cnt < 3) temp[i][j] = true;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (temp[i][j])
				--ice[i][j];

			if (ice[i][j] <= 0)
				ice[i][j] = 0;
		}
	}
}

bool visited[65][65];

int bfs(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({x,y});
	visited[x][y] = true;
	int cnt = 0;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;;
		Q.pop();
		++cnt;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dX[i];
			int ny = y + dY[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (ice[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}

	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;

	N = pow(2, N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> ice[i][j];
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int k;
		cin >> k;

		select(k);
		meltIce();
	}

	int answer{};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			answer += ice[i][j];
		}
	}

	int big{};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (ice[i][j] == 0) continue;
			if (visited[i][j] == false)
				big = max(big, bfs(i, j));
		}
	}

	cout << answer << endl;
	cout << big;

	return 0;
}
