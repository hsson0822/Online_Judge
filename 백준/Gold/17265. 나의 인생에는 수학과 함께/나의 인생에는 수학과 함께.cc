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
char road[6][6];
//int dp[6][6];

int dX[]{ 1,0 };
int dY[]{ 0,1 };

int big = INT_MIN;
int small = INT_MAX;

struct Num
{
	int x;
	int y;
	char oper;
	int sum;
};

void dfs()
{
	queue <Num> Q;
	Q.push(Num{ 1,1,'\0',road[1][1]-'0'});

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		char oper = Q.front().oper;
		int sum = Q.front().sum;
		Q.pop();
		if (isdigit(road[x][y]))
		{
			if (oper == '+')
			{
				sum += road[x][y]-'0';
			}
			else if (oper == '-')
			{
				sum -= road[x][y]-'0';
			}
			else if (oper == '*')
			{
				sum *= road[x][y]-'0';
			}

			if (x == N && y == N)
			{
				big = max(big, sum);
				small = min(small, sum);
				continue;
			}
		}

		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dX[i];
			int ny = y + dY[i];

			if (nx > N || ny > N) continue;

			if (isdigit(road[nx][ny]))
			{
				Q.push(Num{nx,ny,oper, sum});
			}
			else
			{
				Q.push(Num{nx,ny,road[nx][ny], sum});
			}
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
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> road[i][j];
		}
	}

	dfs();

	cout << big << " " << small << "\n";

	return 0;
}
