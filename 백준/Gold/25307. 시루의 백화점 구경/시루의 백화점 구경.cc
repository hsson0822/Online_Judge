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

int N, M, K;
int depart[2001][2001];
bool visited[2001][2001];
queue<pair<int, int>> mannequin;
int dist[2001][2001];

int SX;
int SY;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

const int INF = INT_MAX;
int answer = INT_MAX;


void danger()
{
	while (!mannequin.empty())
	{
		/*int x = get<0>(mannequin.front());
		int y = get<1>(mannequin.front());
		int s = get<2>(mannequin.front());*/
		int x = mannequin.front().first;
		int y = mannequin.front().second;
		mannequin.pop();

		//cout << x << " , " << y <<endl;
		//depart[x][y] = 3;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;

			if (dist[x][y]+1 >= dist[nx][ny]) continue;
			if (dist[x][y] < K)
			{
				mannequin.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;

				if(depart[nx][ny] != 4)
					depart[nx][ny] = 3;
			}
		}
	}
}

void findSeat()
{
	queue<tuple<int, int, int>> Q;
	visited[SX][SY] = true;
	Q.push({ SX,SY,0 });

	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int w = get<2>(Q.front());
		Q.pop();

		if (depart[x][y] == 2)
		{
			answer = min(answer, w);
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (depart[nx][ny] == 1 || depart[nx][ny] == 3) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = true;
			Q.push({ nx,ny,w + 1});

		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	fill(&dist[0][0], &dist[N][M + 1], INF);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> depart[i][j];

			if (depart[i][j] == 4)
			{
				SX = i;
				SY = j;
			}
			else if (depart[i][j] == 3)
			{
				mannequin.push({ i,j});
				dist[i][j] = 0;
			}
		}
	}

	danger();

	//cout << endl;
	//for (int i = 1; i <= N; ++i)
	//{
	//	for (int j = 1; j <= M; ++j)
	//	{
	//		cout << depart[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//
	findSeat();

	if (answer == INT_MAX)
		cout << -1;
	else
		cout << answer;

	return 0;
}