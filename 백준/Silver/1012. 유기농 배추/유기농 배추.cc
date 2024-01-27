#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int farm[50][50];
bool route[50][50];
priority_queue<int, vector<int>, greater<int>> group;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int row;
int col;
int cnt{};

void reset()
{
	memset(farm, 0, 50 * 50 * sizeof(int));
	memset(route, false, 50 * 50 * sizeof(bool));
	while (!group.empty())
		group.pop();
}

void dfs(int r, int c)
{
	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= row || nr < 0 || nc >= col || nc < 0) continue;

		if (route[nr][nc] == false && farm[nr][nc] == 1)
		{
			route[nr][nc] = true;
			++cnt;
			dfs(nr, nc);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{

		cin >> row >> col;

		int size;
		cin >> size;

		for (int i = 0; i < size; ++i)
		{
			int a;
			int b;
			cin >> a >> b;

			farm[a][b] =1;
		}

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (farm[i][j] == 1 && route[i][j] == false)
				{
					route[i][j] = true;
					cnt = 1;
					dfs(i, j);
					group.push(cnt);
				}
			}
		}

		cout << group.size() << endl;

		reset();
	}
	return 0;
}