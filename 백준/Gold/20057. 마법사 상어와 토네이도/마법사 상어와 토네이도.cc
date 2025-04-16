#include <iostream>

using namespace std;

int N;
int sand[500][500];

int dir = 0;
int X;
int Y;

int answer{};

//←, ↓, →, ↑
int dX[]{ 0, 1,0,-1 };
int dY[]{ -1,0,1,0 };

int fiveX[]{ 0,2,0,-2 };
int fiveY[]{ -2,0,2,0 };

int tenX1[]{ -1,1,1,-1 };
int tenY1[]{ -1,-1,1,1 };

int tenX2[]{ 1,1,-1,-1 };
int tenY2[]{ -1,1,1,-1 };

int sevenX1[]{-1,0,1,0};
int sevenY1[]{0,-1, 0,1};

int sevenX2[]{ 1,0,-1,0 };
int sevenY2[]{ 0,1, 0,-1 };

int twoX1[]{ -2,0,2,0 };
int twoY1[]{ 0,-2, 0,2 };

int twoX2[]{ 2,0,-2,0 };
int twoY2[]{ 0,2, 0,-2 };

int oneX1[]{ -1,-1,1,1 };
int oneY1[]{ 1,-1,-1,1 };

int oneX2[]{ 1,-1,-1,1 };
int oneY2[]{ 1,1,-1,-1 };

bool isInside(int x, int y)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N)
		return true;
	else
		return false;
}

void five(int x, int y, double per)
{
	int nx = x + fiveX[dir];
	int ny = y + fiveY[dir];

	int lost = per;

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;

}

void ten(int x, int y, double per)
{
	int nx = x + tenX1[dir];
	int ny = y + tenY1[dir];

	int lost = per;

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;

	nx = x + tenX2[dir];
	ny = y + tenY2[dir];

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;
}

void seven(int x, int y, double per)
{
	int nx = x + sevenX1[dir];
	int ny = y + sevenY1[dir];

	int lost = per;

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;

	nx = x + sevenX2[dir];
	ny = y + sevenY2[dir];

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;

}

void two(int x, int y, double per)
{
	int nx = x + twoX1[dir];
	int ny = y + twoY1[dir];

	int lost = per;

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;


	nx = x + twoX2[dir];
	ny = y + twoY2[dir];

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;
}

void one(int x, int y, double per)
{
	int nx = x + oneX1[dir];
	int ny = y + oneY1[dir];

	int lost = per;
	
	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;

	nx = x + oneX2[dir];
	ny = y + oneY2[dir];

	if (isInside(nx, ny))
		sand[nx][ny] += lost;
	else
		answer += lost;
}

void moveSand(int x, int y)
{
	double f = (double)sand[x][y] * 0.05;
	double t = (double)sand[x][y] * 0.1;
	double s = (double)sand[x][y] * 0.07;
	double tw = (double)sand[x][y] * 0.02;
	double o = (double)sand[x][y] * 0.01;

	sand[x][y] -= (int)(f + (2*(int)t) + (2 * (int)s) + (2 * (int)tw) + (2 * (int)o));

	five(x, y, f);
	ten(x, y, t);
	seven(x, y, s);
	two(x, y, tw);
	one(x, y, o);

	int nx = x + dX[dir];
	int ny = y + dY[dir];

	if (isInside(nx, ny))
		sand[nx][ny] += sand[x][y];
	else
		answer += sand[x][y];

	sand[x][y] = 0;
}

void moveTornado()
{
	int nx = X + dX[dir];
	int ny = Y + dY[dir];

	moveSand(nx, ny);

	X = nx;
	Y = ny;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> sand[i][j];
	
	X = N / 2+1;
	Y = N / 2+1;
	int T{};

	while (true)
	{
		int cnt = (T / 2) +1;
		if (cnt >= N) cnt = N - 1;
		
		for (int c = 0; c < cnt; ++c)
		{
			moveTornado();
		}

		if (X == 1 && Y == 1) break;

		++dir;
		if (dir >= 4)
			dir -= 4;

		++T;
	}

	cout << answer;

	return 0;
}
