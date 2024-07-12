#include <iostream>

using namespace std;

int N;
int M;
int point;
int domino[101][101];
bool fall[101][101];

void solve(int x, int y, int cnt, char dir)
{

	if (x <= 0 || y <= 0 || x > N || y > M) return;

	if (!fall[x][y])
	{
		fall[x][y] = true;
		++point;
	}

	if (dir == 'N')
	{
		for (int i = 0; i < cnt-1; ++i)
		{
			if (x <= 0) break;

			if (!fall[x][y])
			{
				fall[x][y] = true;
				++point;
			}

			--x;

			if (x > 0 && !fall[x][y])
				solve(x, y, domino[x][y], dir);
		}
	}
	else if (dir == 'E')
	{
		for (int i = 0; i < cnt-1; ++i)
		{
			if (y > M) break;

			if (!fall[x][y])
			{
				fall[x][y] = true;
				++point;
			}

			++y;

			if (y <= M && !fall[x][y])
				solve(x, y, domino[x][y], dir);
		}
	}
	else if (dir == 'S')
	{
		for (int i = 0; i < cnt-1; ++i)
		{
			if (x > N) break;

			if (!fall[x][y])
			{
				fall[x][y] = true;
				++point;
			}

			++x;

			if (x <= N && !fall[x][y])
				solve(x, y, domino[x][y], dir);
		}
	}
	else if (dir == 'W')
	{
		for (int i = 0; i < cnt-1; ++i)
		{
			if (y <= 0) break;

			if (!fall[x][y])
			{
				fall[x][y] = true;
				++point;
			}

			--y;

			if (y > 0 && !fall[x][y])
				solve(x, y, domino[x][y], dir);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int R;

	cin >> N >> M >> R;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> domino[i][j];

	for (int r = 0; r < R; ++r)
	{
		int x;
		int y;
		char d;
		cin >> x >> y >> d;

		if (!fall[x][y])
		{	
			solve(x, y, domino[x][y], d);
		}


		cin >> x >> y;

		fall[x][y] = false;
	}

	cout << point << "\n";
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (fall[i][j])
				cout << "F ";
			else
				cout << "S ";
		}
		cout << endl;
	}


	return 0;
}