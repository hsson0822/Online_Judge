#include <iostream>

using namespace std;

int table[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	for (int i = 0; i < M ; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		table[a][b] = 1;
		table[b][a] = -1;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (table[i][k] == table[k][j] && table[i][k] != 0)
					table[i][j] = table[i][k];
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		int cnt{};
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)continue;
			if (table[i][j] == 0)
				++cnt;
		}
		cout << cnt << "\n";
	}

	return 0;
}