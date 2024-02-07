#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int normalCnt;
int abnormalCnt;

char normalColor[101][101];
char abnormalColor[101][101];
bool visited[101][101];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

void bfsNor(int x, int y, char col)
{
	queue<pair<int, int>> que;
	que.push(pair(x, y));

	while (!que.empty())
	{
		auto pos = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (normalColor[nx][ny] == col && visited[nx][ny] == false)
			{
			
				visited[nx][ny] = true;
				que.push(pair(nx, ny));
			}
		}
	}
}

void bfsAbnor(int x, int y, char col)
{
	queue<pair<int, int>> que;
	que.push(pair(x, y));

	while (!que.empty())
	{
		auto pos = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (abnormalColor[nx][ny] == col && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				que.push(pair(nx, ny));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char ch;
			cin >> ch;
			normalColor[i][j] = ch;

			if (ch == 'G')
				ch = 'R';

			abnormalColor[i][j] = ch;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == false)
			{
				++normalCnt;
				visited[i][j] = true;
				bfsNor(i, j, normalColor[i][j]);
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == false)
			{
				++abnormalCnt;
				visited[i][j] = true;
				bfsAbnor(i, j, abnormalColor[i][j]);
			}
		}
	}

	cout << normalCnt << " " << abnormalCnt;

	return 0;
}