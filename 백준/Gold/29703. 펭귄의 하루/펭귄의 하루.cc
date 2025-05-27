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
int M;
char village[1001][1001];
int Fcost[1001][1001];
int Hcost[1001][1001];
const int INF = INT_MAX;

int SX;
int SY;

int HX;
int HY;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

void findFood()
{
	queue<tuple<int, int, int>> Q;
	Q.push({ SX,SY,0 });
	Fcost[SX][SY] = 0;

	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int c = get<2>(Q.front());
		Q.pop();

		if (Fcost[x][y] < c) continue;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = c + 1;

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (village[nx][ny] == 'D') continue;

			if (Fcost[nx][ny] > nc)
			{
				Fcost[nx][ny] = nc;
				Q.push({ nx,ny,nc });
			}
		}
	}
}

void findHome()
{
	queue<tuple<int, int, int>> Q;
	Q.push({ HX,HY,0 });
	Hcost[HX][HY] = 0;

	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int c = get<2>(Q.front());
		Q.pop();

		if (Hcost[x][y] < c) continue;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = c + 1;

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (village[nx][ny] == 'D') continue;

			if (Hcost[nx][ny] > nc)
			{
				Hcost[nx][ny] = nc;
				Q.push({ nx,ny,nc });
			}
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
			cin >> village[i][j];

			if (village[i][j] == 'S')
			{
				SX = i;
				SY = j;
			}
			else if (village[i][j] == 'H')
			{
				HX = i;
				HY = j;
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			Fcost[i][j] = INF;
			Hcost[i][j] = INF;
		}
	}
	findFood();
	findHome();

	int answer = INT_MAX;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (village[i][j] == 'F' && Hcost[i][j] != INF && Fcost[i][j] != INF)
			{
				int sum = Hcost[i][j] + Fcost[i][j];
				answer = min(answer, sum);
			}
		}
	}

	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}
