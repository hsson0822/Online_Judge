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

int N, M;
int wall[101][101];
queue<pair<int, int>> mush[6];

int dx[]{ 1,1,1,0,0,-1,-1,-1 };
int dy[]{ 1,0,-1,1,-1,1,0,-1 };

int areaCnt;
bool visited[101][101];

void spread(int k)
{
	queue < tuple<int, int, int>> Q;
	while (!mush[k].empty())
	{
		int x = mush[k].front().first;
		int y = mush[k].front().second;
		mush[k].pop();

		Q.push({ x,y,k - 1 });
	}

	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int t = get<2>(Q.front());
		Q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (wall[nx][ny] >= k) continue;

			wall[nx][ny] = k;

			if (t > 0)
			{
				Q.push({ nx,ny,t - 1 });
			}
			else
			{
				mush[k].push({ nx,ny });
			}
		}
	}
}

int dirX[]{ 1,0,-1,0 };
int dirY[]{ 0,1,0,-1 };

void linked(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	visited[x][y] = true;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dirX[i];
			int ny = y + dirY[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (visited[nx][ny]) continue;
			if (wall[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			char ch;
			cin >> ch;
			wall[i][j] = ch - '0';

			if (wall[i][j] != 0)
				mush[wall[i][j]].push({ i,j });
		}
	}

	int time{};

	memset(visited, false, sizeof(visited));
	areaCnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (wall[i][j] != 0 && visited[i][j] != true)
			{
				++areaCnt;
				if (areaCnt > 1)
					break;

				linked(i, j);
			}
		}

		if (areaCnt > 1)
			break;
	}

	if (areaCnt == 1)
	{
		cout << time;
		return 0;
	}

	while (true)
	{
		++time;

		for (int i = 5; i >= 1; --i)
		{
			if (mush[i].size() != 0)
				spread(i);
		}

		memset(visited, false, sizeof(visited));
		areaCnt = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (wall[i][j] != 0 && visited[i][j] != true)
				{
					++areaCnt;
					if (areaCnt > 1)
						break;

					linked(i, j);
				}
			}

			if (areaCnt > 1)
				break;
		}

		if (areaCnt == 1)
		{
			cout << time;
			break;
		}

		//cout << time << endl;
		//for (int i = 1; i <= N; ++i)
		//{
		//	for (int j = 1; j <= M; ++j)
		//	{
		//		cout << visited[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
	}



	return 0;
}