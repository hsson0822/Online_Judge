#include <iostream>

using namespace std;

int R;
int C;
int nemo[26][26];

int answer;

void dfs(int r, int c)
{
	if (r > R)
	{
		++answer;
		return;
	}

	if (c < C)
		dfs(r, c + 1);
	else
		dfs(r + 1, 1);

	if (!(nemo[r - 1][c - 1] && nemo[r - 1][c] && nemo[r][c - 1]))
	{
		nemo[r][c] = 1;

		if (c < C)
			dfs(r, c + 1);
		else
			dfs(r + 1, 1);

		nemo[r][c] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	dfs(1, 1);

	cout << answer;

	return 0;
}