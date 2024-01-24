#include <iostream>

using namespace std;

long long nums[100001];
long long dp[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	for (int i = 1; i <= count; ++i)
	{
		int n;
		cin >> n;
		nums[i] = n;
	}

	dp[1] = nums[1];
	long long bigger = nums[1];

	for (int i = 2; i <= count; ++i)
	{
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		bigger = max(dp[i], bigger);
	}

	cout << bigger;

	return 0;
}