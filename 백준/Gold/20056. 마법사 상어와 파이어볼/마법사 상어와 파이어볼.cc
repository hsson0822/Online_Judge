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

struct FireBall {
	int r;
	int c;
	int m;
	int speed;
	int dir;
};

int N;
int M;
int K;

vector<FireBall> fireBalls;
vector<FireBall> field[51][51];

int dX[]{ -1,-1,0,1,1,1,0,-1 };
int dY[]{ 0,1,1,1,0,-1,-1,-1 };

void moveBall()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			field[i][j].clear();

	for (int i = 0; i < fireBalls.size(); ++i)
	{
		int x = fireBalls[i].r;
		int y = fireBalls[i].c;
		int m = fireBalls[i].m;
		int speed = fireBalls[i].speed;
		int dir = fireBalls[i].dir;

		int move = speed % N;
		int nx = x + dX[fireBalls[i].dir] * move;
		int ny = y + dY[fireBalls[i].dir] * move;


		if (nx <= 0) nx += N;
		if (nx > N) nx -= N;

		if (ny <= 0) ny += N;
		if (ny > N) ny -= N;

		field[nx][ny].push_back({ nx,ny,m,speed,dir });

		fireBalls[i].r = nx;
		fireBalls[i].c = ny;
	}
}

void divideBall()
{
	vector<FireBall> temp;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (field[i][j].size() == 0) continue;

			if (field[i][j].size() == 1)
			{
				temp.push_back(field[i][j][0]);
				continue;
			}

			int nm = 0;
			int ns = 0;
			int cnt = field[i][j].size();

			bool even = true;
			bool odd = true;

			for (int k = 0; k < field[i][j].size(); ++k)
			{
				nm += field[i][j][k].m;
				ns += field[i][j][k].speed;

				if (field[i][j][k].dir % 2 == 0)
					odd = false;
				else
					even = false;
			}

			int m = nm / 5;
			int speed = ns / cnt;
			if (m == 0) continue;
			if (even || odd)
			{
				for (int k = 0; k < 4; ++k)
					temp.push_back({ i,j,m,speed,k * 2 });
			}
			else
			{
				for (int k = 0; k < 4; ++k)
					temp.push_back({ i,j,m,speed,(k * 2) + 1 });
			}
		}
	}

	fireBalls = temp;
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

		fireBalls.push_back({ r,c,m,s,d });
		field[r][c].push_back({ r,c,m,s,d });
	}

	for (int i = 0; i < K; ++i)
	{
		moveBall();
		divideBall();
	}

	int answer{};
	for (int i = 0; i < fireBalls.size(); ++i)
		answer += fireBalls[i].m;

	cout << answer;

	return 0;
}
