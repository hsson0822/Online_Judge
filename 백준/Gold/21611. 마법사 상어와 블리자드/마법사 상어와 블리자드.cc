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
int sharkX;
int sharkY;

int field[50][50];

int dX[]{ 0, -1,1,0,0 };
int dY[]{ 0,0,0,-1,1 };

int torDirX[]{ 0,1,0,-1 };
int torDirY[]{ -1,0,1,0 };

int bombCnt[4]{};

queue<int> getField()
{
	int dir = 0;
	int t = 0;
	int x = sharkX;
	int y = sharkY;

	queue<int> nums;

	while (true)
	{
		int cnt = (t / 2) + 1;
		if (cnt >= N) cnt = N - 1;

		for (int i = 0; i < cnt; ++i)
		{
			x = x + torDirX[dir];
			y = y + torDirY[dir];

			if (field[x][y] == 0) continue;

			nums.push(field[x][y]);
			field[x][y] = 0;
		}
		if (x == 1 && y == 1) break;

		++dir;
		if (dir >= 4)
			dir -= 4;

		++t;
	}

	return nums;
}

void setField(queue<int> Q)
{
	int dir = 0;
	int t = 0;
	int x = sharkX;
	int y = sharkY;

	while (!Q.empty())
	{
		int cnt = (t / 2) + 1;
		if (cnt >= N) cnt = N - 1;

		for (int i = 0; i < cnt; ++i)
		{
			x = x + torDirX[dir];
			y = y + torDirY[dir];

			field[x][y] = Q.front();
			Q.pop();

			if (Q.empty()) break;
			if (x == 1 && y == 1) break;
		}

		if (Q.empty()) break;
		if (x == 1 && y == 1) break;

		++dir;
		if (dir >= 4)
			dir -= 4;

		++t;
	}
}

void arrangeField()
{
	queue<int> Q = getField();
	setField(Q);

}

void breakBall(int d, int s)
{
	for (int i = 1; i <= s; ++i)
	{
		int nx = sharkX + (dX[d] * i);
		int ny = sharkY + (dY[d] * i);

		field[nx][ny] = 0;
	}

	setField(getField());
}

void bombBall()
{
	queue<int> Q = getField();
	queue<int> temp;
	queue<int> warehouse;

	int before = 0;
	int cnt{};

	while (!Q.empty())
	{
		int n = Q.front();
		Q.pop();

		if (before == 0)
		{
			before = n;
			warehouse.push(n);
			continue;
		}

		if (before == n)
		{
			warehouse.push(n);
		}
		else
		{

			if (warehouse.size() >= 4)
			{
				bombCnt[before] += warehouse.size();
				while (!warehouse.empty()) { warehouse.pop(); }
				++cnt;
			}
			else
			{
				while (!warehouse.empty())
				{
					temp.push(warehouse.front());
					warehouse.pop();
				}
			}
			before = n;
			warehouse.push(n);
		}
	}

	if (warehouse.size() >= 4)
	{
        bombCnt[before] += warehouse.size();
		while (!warehouse.empty()) { warehouse.pop(); }
	}
	else
	{
		while (!warehouse.empty())
		{
			temp.push(warehouse.front());
			warehouse.pop();
		}
	}

	setField(temp);

	if (cnt >= 1)
		bombBall();
}

void groupBall()
{
	queue<int> Q = getField();
	queue<int> temp;
	int cnt{};
	int before = 0;


	while (!Q.empty())
	{
		int n = Q.front();
		Q.pop();

		if (before == 0)
		{
			before = n;
			++cnt;
			continue;
		}

		if (before == n)
		{
			++cnt;
		}
		else
		{
			temp.push(cnt);
			temp.push(before);
			
			before = n;
			cnt = 1;
		}
	}

	temp.push(cnt);
	temp.push(before);

	setField(temp);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	sharkX = N / 2 + 1;
	sharkY = N / 2 + 1;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> field[i][j];

	for (int i = 0; i < M; ++i)
	{
		int d;
		int s;
		cin >> d >> s;

		breakBall(d, s);
		bombBall();
		groupBall();
	}

	int answer{};
	for (int i = 1; i < 4; ++i)
		answer += i * bombCnt[i];

	cout << answer;

	return 0;
}
