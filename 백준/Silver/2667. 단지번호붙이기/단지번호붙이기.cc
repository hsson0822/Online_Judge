#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int apart[25][25];
bool route[25][25];
priority_queue<int, vector<int>, greater<int>> group;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int cnt{};

void dfs(int size, int r, int c)
{
	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= size || nr < 0 || nc >= size || nc < 0) continue;

		if (route[nr][nc] == 0 && apart[nr][nc] == 1)
		{
			route[nr][nc] = true;
			++cnt;
			dfs(size, nr, nc);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size;
	cin >> size;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			char a;
			cin >> a;

			apart[i][j] = a - '0';
		}
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (apart[i][j] == 1 && route[i][j] == false)
			{
				route[i][j] = true;
				cnt = 1;
				dfs(size, i, j);
				group.push(cnt);
			}
		}
	}

	cout << group.size() << endl;
	int time = group.size();
	for (int i = 0; i < time; ++i)
	{
		cout << group.top() << endl;
		group.pop();
	}
	int a;
	cin >> a;
	return 0;
}