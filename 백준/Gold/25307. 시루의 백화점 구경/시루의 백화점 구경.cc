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
queue<tuple<int, int, int>> mannequin;
bool visited[2001][2001];

int SX;
int SY;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

int mx[]{ 1,1,1,0,0,-1,-1,-1 };
int my[]{ 1,0,-1,1,-1,1,0,-1 };

int answer = INT_MAX;

void danger()
{
	while (!mannequin.empty())
	{
		int x = get<0>(mannequin.front());
		int y = get<1>(mannequin.front());
		int s = get<2>(mannequin.front());
		mannequin.pop();

		if (s == 0)
		{
			//depart[x][y] = 3;
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (visited[nx][ny] == true) continue;


			visited[nx][ny] = true;
			if (depart[nx][ny] != 4)
				depart[nx][ny] = 3;
			mannequin.push({ nx,ny,s - 1 });
		}
	}
}

void findSeat()
{
	memset(visited, false, sizeof(visited));

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
			Q.push({ nx,ny,w + 1 });

		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

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
				mannequin.push({ i,j,K });
				visited[i][j] = true;
			}
		}
	}

	danger();

	/*cout << endl;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout << depart[i][j] << " ";
		}
		cout << endl;
	}*/

	findSeat();

	if (answer == INT_MAX)
		cout << -1;
	else
		cout << answer;

	return 0;
}