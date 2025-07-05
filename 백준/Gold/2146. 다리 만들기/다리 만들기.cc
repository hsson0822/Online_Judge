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
int ground[101][101];
bool visited[101][101];
int section[101][101];
int sectionNum{};

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

int answer = INT_MAX;

void findSection(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	visited[x][y] = true;
	section[x][y] = sectionNum;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (visited[nx][ny]) continue;
			if (ground[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			section[nx][ny] = sectionNum;
			Q.push({ nx,ny });
		}
	}
}

void connect(int x, int y)
{
	memset(visited, false, sizeof(visited));

	queue<tuple<int,int, int>> Q;
	Q.push({ x,y,0 });
	visited[x][y] = true;
	
	int num = section[x][y];

	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int w = get<2>(Q.front());
		Q.pop();

		if (ground[x][y] != 0 && num != section[x][y])
		{
			//cout << num << " , " << section[x][y] << endl;
			answer = min(answer, w-1);
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (visited[nx][ny]) continue;
			if (section[nx][ny] == num) continue;

			visited[nx][ny] = true;
			Q.push({ nx,ny,w+1 });
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> ground[i][j];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (ground[i][j] != 0 && visited[i][j] == false)
			{
				++sectionNum;
				findSection(i, j);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if(ground[i][j] != 0)
				connect(i, j);
		}
	}

	/*for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << section[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << answer;

	return 0;
}