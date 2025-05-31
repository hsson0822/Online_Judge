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
int village[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> virus1;
queue<pair<int, int>> virus2;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

void bfs()
{
	int size = virus1.size();
	for (int t = 0; t < size; ++t)
	{
		int x = virus1.front().first;
		int y = virus1.front().second;
		virus1.pop();

		if (village[x][y] == 3)
			continue;

		visited[x][y] = 2;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (visited[nx][ny] != 0) continue;
			if (village[nx][ny] == -1 ||
				village[nx][ny] == 1 ||
				village[nx][ny] == 2 ||
				village[nx][ny] == 3)
				continue;

			visited[nx][ny] = 1;
			village[nx][ny] = 1;
			virus1.push({ nx,ny });
		}
	}

	size = virus2.size();
	for (int t = 0; t < size; ++t)
	{
		int x = virus2.front().first;
		int y = virus2.front().second;
		virus2.pop();

		visited[x][y] = 2;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (village[nx][ny] == -1 ||
				village[nx][ny] == 2 ||
				village[nx][ny] == 3)
				continue;

			if (village[nx][ny] == 1 && visited[nx][ny] == 1)
			{
				village[nx][ny] = 3;
				visited[nx][ny] = 2;
				continue;
			}
			else if( village[nx][ny] == 1)
				continue;

			visited[nx][ny] = 1;
			village[nx][ny] = 2;
			virus2.push({ nx,ny });
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

			if (village[i][j] == 1)
			{
				virus1.push({ i,j });
				visited[i][j] = 2;
			}
			else if (village[i][j] == 2)
			{
				virus2.push({ i,j });
				visited[i][j] = 2;
			}

		}
	}

	while (virus1.size() != 0 || virus2.size() != 0)
	{
		bfs();

		/*for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cout << village[i][j];
			}
			cout << endl;
		}
		cout << endl;*/
	}

	int one{};
	int two{};
	int three{};
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (village[i][j] == 1)
				++one;
			else if (village[i][j] == 2)
				++two;
			else if (village[i][j] == 3)
				++three;
		}
	}

	cout << one << " " << two << " " << three;
	
	return 0;
}
