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

class Shark
{
public:
	int r{};
	int c{};
	int s{};
	int d{};
	int z{};

	Shark() {}

	Shark(int r, int c, int s, int d, int z)
		:r(r), c(c), s(s), d(d), z(z) {}
};

int R, C, M;
int fisher{};
int caught{};
int water[101][101];
map<int, Shark> sharks;

int dr[]{ 0,-1,1,0,0 };
int dc[]{ 0,0,0,1,-1 };

void sharkMove()
{
	int nextWater[101][101];
	fill(&nextWater[0][0], &nextWater[R][C+1], 0);

	for (int i = 1; i <= M; ++i)
	{
		int name = i;
		Shark s = sharks[name];

		if (sharks[name].z == 0) continue;
		//cout << name << endl;

		int move = s.s;
		if (s.d == 1 || s.d == 2)
			move %= (R - 1) * 2;
		else
			move %= (C - 1) * 2;

		for (int j = 0; j < move; ++j)
		{
			int nr = s.r + dr[s.d];
			int nc = s.c + dc[s.d];

			if (nr < 1 || nr > R || nc < 1 || nc > C)
			{
				if (s.d == 1) s.d = 2;
				else if (s.d == 2) s.d = 1;
				else if (s.d == 3) s.d = 4;
				else if (s.d == 4) s.d = 3;

				nr = s.r + dr[s.d];
				nc = s.c + dc[s.d];
			}

			s.r = nr;
			s.c = nc;
		}

		//cout << s.r << " " << s.c << endl;
		if (nextWater[s.r][s.c] != 0)
		{
			int beforeName = nextWater[s.r][s.c];

			if (sharks[beforeName].z < s.z)
			{
				sharks[beforeName].z = 0;
				//cout << name << " Eat1 : " << beforeName << endl;
			}
			else if (sharks[beforeName].z > s.z)
			{
				sharks[name].z = 0;
				//cout << beforeName << " Eat2 : " << name << endl;
				continue;
			}
		}

		sharks[name].r = s.r;
		sharks[name].c = s.c;
		sharks[name].d = s.d;

		nextWater[s.r][s.c] = name;
	}

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			water[i][j] = nextWater[i][j];
		}
	}

}

void show()
{
	cout << endl;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (water[i][j] != 0)
				cout << water[i][j] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;

	fill(&water[0][0], &water[R][C + 1], 0);

	for (int i =1; i <= M; ++i)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		water[r][c] = i;
		sharks[i] = Shark(r, c, s, d, z);
	}

	//show();

	while (fisher < C)
	{
		++fisher;

		for (int h = 1; h <= R; ++h)
		{
			if (water[h][fisher] != 0)
			{
				int sharkName = water[h][fisher];
				water[h][fisher] = 0;

				caught += sharks[sharkName].z;
				sharks[sharkName].z = 0;
				//cout << "Catch : " << sharks[sharkName].z << endl;
				//sharks.erase(sharkName);

				break;
			}
		}

		sharkMove();

		//show();
	}

	cout << caught;

	return 0;
}