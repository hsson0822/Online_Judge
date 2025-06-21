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
char game[21][21];

pair<int, int> APos;
pair<int, int> BPos;
bool visited[21][21][21][21];

int dx[]{ 0,1,0,-1,0,1,1,-1,-1 };
int dy[]{ 0,0,1,0,-1,1,-1,1,-1 };

const int INF = INT_MAX;

struct State
{
	int ax, ay, bx, by, c;
	State(int ax, int ay, int bx, int by, int c) : ax(ax), ay(ay), bx(bx), by(by), c(c) {}
};

void bfs()
{
	queue<State> Q;
	Q.push({ APos.first, APos.second,BPos.first,BPos.second, 0 });
	visited[APos.first][APos.second][BPos.first][BPos.second] = true;

	while (!Q.empty())
	{
		State cur = Q.front();
		Q.pop();
		
		int ax = cur.ax;
		int ay = cur.ay;
		int bx = cur.bx;
		int by = cur.by;
		int c = cur.c;

		if (ax == BPos.first && ay == BPos.second && bx == APos.first && by == APos.second)
		{
			cout << c;
			return;
		}

		for (int i = 0; i < 9; ++i)
		{
			int nax = ax + dx[i];
			int nay = ay + dy[i];

			if (nax <= 0 || nay <= 0 || nax > N || nay > M) continue;
			if (game[nax][nay] == 'X')continue;

			for (int j = 0; j < 9; ++j)
			{
				int nbx = bx + dx[j];
				int nby = by + dy[j];

				if (nbx <= 0 || nby <= 0 || nbx > N || nby > M) continue;
				if (game[nbx][nby] == 'X')continue;

				if (visited[nax][nay][nbx][nby]) continue;
				if (nax == nbx && nay == nby) continue;
				if (nax == bx && nay == by && nbx == ax && nby == ay) continue;

				Q.push({ nax,nay,nbx,nby,c + 1 });
				visited[nax][nay][nbx][nby] = true;
			}
		}
	}
	cout << -1;
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
			cin >> game[i][j];
			if (game[i][j] == 'A')
				APos = { i,j };
			if (game[i][j] == 'B')
				BPos = { i,j };
		}
	}

	bfs();

	return 0;
}
