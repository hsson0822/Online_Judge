#include <iostream>

using namespace std;

long long house[100001][15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 1; i <= 14; ++i)
	{
		house[0][i] = i;
	}

	for (int t = 0; t < testCase; ++t)
	{
		int k;
		cin >> k;

		int n;
		cin >> n;

		for (int i = 1; i <= k; ++i)
		{
			int j{};
			long long sum{};
			for (j = 1; j <= n; ++j)
			{
				sum += house[i - 1][j];
				house[i][j] = sum;
			}
		}

		cout << house[k][n] << endl;
	}

	return 0;
}