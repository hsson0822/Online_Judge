#include <iostream>

using namespace std;

int N;
int M;
int x;
int y;
int fr;
int ba;
pair<int, int> dir[4]{ {-1,0},{0,1}, {1,0}, {0,-1 } };

int room[51][51];

void left(int& front, int& back)
{
	--front;
	--back;

	if (front < 0) front = 3;
	if (back < 0) back = 3;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	cin >> x >> y >> fr;
	if (fr == 0) ba = 2;
	else if (fr == 1) ba = 3;
	else if (fr == 2) ba = 0;
	else if (fr == 3) ba = 1;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int n;
			cin >> n;
			room[i][j] = n;
		}
	}

	int cnt{};
	while (true)
	{
		if (room[x][y] == 0)
		{
			++cnt;
			room[x][y] = 2;
		}

		bool next = false;
		for (int i = 0; i < 4; ++i)
		{
			int nx = dir[i].first + x;
			int ny = dir[i].second + y;

			if (room[nx][ny] == 0)
			{
				next = true;
				break;
			}
		}

		if (!next)
		{
			int nx = x + dir[ba].first;
			int ny = y + dir[ba].second;

			if (room[nx][ny] == 1)
				break;
			else
			{
				x = nx;
				y = ny;
			}

		}
		else
		{
			left(fr, ba);

			int nx = x + dir[fr].first;
			int ny = y + dir[fr].second;

			if (room[nx][ny] == 0)
			{
				x = nx;
				y = ny;
			}

		}
	}

	cout << cnt;

	return 0;
}