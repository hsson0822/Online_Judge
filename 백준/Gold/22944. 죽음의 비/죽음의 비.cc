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
int H;
int D;

int SX;
int SY;
int EX;
int EY;

char field[501][501];
int visited[501][501];

int dX[]{ 1,0,-1,0 };
int dY[]{ 0,1,0,-1 };


struct Status
{
	int x;
	int y;
	int hp;
	int um;
	int step;
};

int bfs(int x, int y)
{
	queue<Status> Q;
	visited[x][y] = H;
	Q.push(Status{ x,y,H,0,0 });

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int hp = Q.front().hp;
		int um = Q.front().um;
		int step = Q.front().step;
		Q.pop();

		if (x == EX && y == EY)
			return step;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dX[i];
			int ny = y + dY[i];
			int nh = hp;
			int nu = um;
			int ns = step+1;

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

			if (field[nx][ny] == '.')
			{
				if (nu <= 0)
					--nh;
				else
					--nu;
			}
			else if (field[nx][ny] == 'U')
			{
				nu = D;
				if (nu <= 0)
					--nh;
				else
					--nu;
			}

			if (nh <= 0) continue;

			if (visited[nx][ny] < nh + nu)
			{
				visited[nx][ny] = nh + nu;
				Q.push(Status{ nx,ny, nh, nu, ns });
			}


		}
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> H >> D;

	for (int i = 1; i <= N; ++i)
	{

		for (int j = 1; j <= N; ++j)
		{
			cin >> field[i][j];

			if (field[i][j] == 'S')
			{
				SX = i;
				SY = j;
			}
			else if (field[i][j] == 'E')
			{
				EX = i;
				EY = j;
			}
		}
	}

	fill(&visited[1][1], &visited[N + 1][N + 1], 0);

	int answer = bfs(SX, SY);
	
	cout << answer;

	return 0;
}
