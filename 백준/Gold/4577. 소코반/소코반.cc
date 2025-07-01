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
char ware[16][16];
bool hole[16][16];

int T;

int personX;
int personY;

int correctCnt{};
bool isClear;

void output();

void reset()
{
	memset(hole, false, sizeof(hole));
	correctCnt = 0;
	isClear = false;
}

void input()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> ware[i][j];

			if (ware[i][j] == '+')
			{
				++correctCnt;
				hole[i][j] = true;
				ware[i][j] = '.';
			}
			else if (ware[i][j] == 'W' || ware[i][j] == 'B')
			{
				++correctCnt;
				hole[i][j] = true;
				ware[i][j] = tolower(ware[i][j]);
			}

			if (ware[i][j] == 'w' || ware[i][j] == 'W')
			{
				personX = i;
				personY = j;
			}

		}
	}
}

bool checkGame()
{
	int cnt{};
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (hole[i][j])
				if (ware[i][j] == 'b')
					++cnt;

	//cout << correctCnt << " , " << cnt << endl;
	if (correctCnt == cnt)
	{
		isClear = true;
		return true;
	}

	return false;
}

int dx[]{ 0,-1,1,0,0 };
int dy[]{ 0,0,0,-1,1 };

void move()
{
	string order;
	cin >> order;

	for (char ch : order)
	{
		int dir{};

		if (ch == 'U') dir = 1;
		else if (ch == 'D') dir = 2;
		else if (ch == 'L') dir = 3;
		else if (ch == 'R') dir = 4;

		int nx = personX + dx[dir];
		int ny = personY + dy[dir];

		if (ware[nx][ny] == '#') continue;

		if (ware[nx][ny] == 'b' || ware[nx][ny] == 'B')
		{
			int overX = nx + dx[dir];
			int overY = ny + dy[dir];

			if (ware[overX][overY] == '#' || ware[overX][overY] == 'b' || ware[overX][overY] == 'B')
				continue;

			ware[overX][overY] = ware[nx][ny];
			ware[nx][ny] = '.';
		}

		ware[nx][ny] = 'w';
		ware[personX][personY] = '.';

		personX = nx;
		personY = ny;

		if (checkGame())
		{
			//cout << "A" << endl;
			return;
		}

		//cout << "ORDER : " << ch;
		//output();

	}
}

void output()
{
	cout << "Game "<< T <<": ";
	if (isClear)
		cout << "complete" << endl;
	else
		cout << "incomplete" << endl;

	//cout << endl;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (hole[i][j])
			{
				if (ware[i][j] == '.')
					cout << '+';
				else if (ware[i][j] == 'b')
					cout << 'B';
				else if (ware[i][j] == 'w')
					cout << 'W';
			}
			else
			{
				cout << ware[i][j];
			}
		}
		cout << endl;
	}
	//cout << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> N >> M;

		if (N == 0 && M == 0) break;

		++T;

		reset();

		input();

		move();

		output();

	}

	return 0;
}