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
int cheese[101][101];
bool isOut[101][101];
bool visited[101][101];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

queue<pair<int, int>> cheeseQ;
int cheeseCnt{};
int Time{};

void checkOut()
{
	memset(isOut, false, sizeof(isOut));

	queue<pair<int, int>> Q;
	isOut[1][1] = true;
	Q.push({1,1});

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		//cout << "A" << endl;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (isOut[nx][ny]) continue;
			if (cheese[nx][ny] == 1) continue;

			isOut[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

void bfs()
{
	int size = cheeseQ.size();

	for(int t= 0 ; t<size ; ++t)
	{
		int x = cheeseQ.front().first;
		int y = cheeseQ.front().second;
		cheeseQ.pop();
		//cout << "B" << endl;

		int cnt{};
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (cheese[nx][ny] == 1) continue;
			if (isOut[nx][ny])
				++cnt;
		}

		if (cnt >= 2)
		{
			--cheeseCnt;
			cheese[x][y] = 0;
		}
		else
			cheeseQ.push({ x,y });

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
			cin >> cheese[i][j];

			if (cheese[i][j] == 1)
			{
				cheeseQ.push({ i,j });
				++cheeseCnt;
			}
		}
	}

	
	while (cheeseCnt > 0)
	{
		++Time;
		//cout << "Time : " << Time << endl;
		checkOut();
		bfs();
	}

	cout << Time;
	
	return 0;
}
