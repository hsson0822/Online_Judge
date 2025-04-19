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

class FireBall
{
public:
	int r;
	int c;
	int mat;
	int speed;
	int dir;

	FireBall(int r, int c, int m, int s, int d) : r(r), c(c), mat(m), speed(s), dir(d)
	{}
};

class Ball
{
public:
	int mat;
	int speed;
	int dir;
	int cnt;
	int odd;
	int even;
};

int N;
int M;
int K;

vector<FireBall> fireBalls;
Ball field[51][51];

int dX[]{ -1,-1,0,1,1,1,0,-1 };
int dY[]{ 0,1,1,1,0,-1,-1,-1 };

int mergeX[]{ 1,0,-1,0 };
int mergeY[]{ 0,1,0,-1 };

void moveBall()
{
	for (int i = 0; i < fireBalls.size(); ++i)
	{
		int x = fireBalls[i].r;
		int y = fireBalls[i].c;
		int speed = fireBalls[i].speed;

		int move = speed % N;
		int nx = x + dX[fireBalls[i].dir] * move;
		int ny = y + dY[fireBalls[i].dir] * move;


		if (nx <= 0) nx += N;
		if (nx > N) nx -= N;

		if (ny <= 0) ny += N;
		if (ny > N) ny -= N;


		fireBalls[i].r = nx;
		fireBalls[i].c = ny;
	}
}

void reset()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			field[i][j].mat = 0;
			field[i][j].speed = 0;
			field[i][j].dir = 0;
			field[i][j].cnt = 0;
			field[i][j].odd = 0;
			field[i][j].even = 0;
		}
	}
}

void mergeBall()
{
	reset();

	for (int i = 0; i < fireBalls.size(); ++i)
	{
		int x = fireBalls[i].r;
		int y = fireBalls[i].c;

		field[x][y].mat += fireBalls[i].mat;
		field[x][y].speed += fireBalls[i].speed;
		field[x][y].dir += fireBalls[i].dir;
		++field[x][y].cnt;

		if (fireBalls[i].dir % 2 == 0)
			++field[x][y].even;
		else
			++field[x][y].odd;
	}

	fireBalls.clear();
}

void divideBall()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (field[i][j].cnt == 0) continue;

			if (field[i][j].cnt == 1)
			{
				fireBalls.push_back(FireBall{ i,j,field[i][j].mat,field[i][j].speed,field[i][j].dir });
				continue;
			}

			int nm = floor((double)field[i][j].mat / 5.0);
			if (nm <= 0) continue;

			int ns = floor((double)field[i][j].speed / (double)field[i][j].cnt);

			for (int k = 0; k < 4; ++k)
			{
				if (field[i][j].cnt == field[i][j].odd)
					fireBalls.push_back(FireBall{ i,j,nm,ns,k * 2 });
				else if (field[i][j].cnt == field[i][j].even)
					fireBalls.push_back(FireBall{ i,j,nm,ns,k * 2 });
				else
					fireBalls.push_back(FireBall{ i,j,nm,ns,(k * 2) + 1 });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < M; ++i)
	{
		int r;
		int c;
		int m;
		int s;
		int d;
		cin >> r >> c >> m >> s >> d;

		fireBalls.push_back(FireBall{ r,c,m,s,d });
	}

	for (int i = 0; i < K; ++i)
	{
		moveBall();
		mergeBall();
		divideBall();

	}

	int answer{};
	for (int i = 0; i < fireBalls.size(); ++i)
		answer += fireBalls[i].mat;

	cout << answer;

	return 0;
}
