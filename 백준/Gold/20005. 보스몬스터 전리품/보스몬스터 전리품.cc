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

int N, M, P;
char world[1001][1001];
int visited[1001][1001][27];

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

map<char, pair<int, int>> position;
map<char, int> bossDamage;
map<char, int> damage;
int alpha[26] = { 0, };

int BX;
int BY;
int bossHP;

void bfs(int x, int y , char c)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	visited[x][y][c] = 1;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (world[nx][ny] == 'X') continue;
			if (visited[nx][ny][c]) continue;
			if (world[nx][ny] == 'B') {
				alpha[c - 'a'] = visited[x][y][c];
				return;
			}
			visited[nx][ny][c] = visited[x][y][c] + 1;
			Q.push({ nx, ny});
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> P;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> world[i][j];
		}
	}

	for (int i = 0; i < P; ++i)
	{
		char ch;
		int d;
		cin >> ch >> d;
		damage[ch] = d;
	}

	cin >> bossHP;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (world[i][j] >= 'a' && world[i][j] <= 'z')
				bfs(i, j, world[i][j]);

	while (bossHP > 0)
	{
		for (int j = 1; j <= 1000000; j++)
		{
			int cnt = 0;
			for (int i = 0; i < 26; i++)
			{
				if (alpha[i] <= j && alpha[i] > 0) {
					bossHP -= damage[i + 'a'];
					cnt++;
				}
			}
			if (bossHP <= 0) {
				cout << cnt;
				return 0;
			}
		}
	}

	return 0;
}
