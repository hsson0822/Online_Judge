#include <iostream>

using namespace std;

long long sum[501][501];
long long num[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;
	
	int answer{};
	for (int i = 1; i <= count; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> num[i][j];
			sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + num[i][j];
			if (answer < sum[i][j])
				answer = sum[i][j];
		}
	}

	cout << answer;

	return 0;
}