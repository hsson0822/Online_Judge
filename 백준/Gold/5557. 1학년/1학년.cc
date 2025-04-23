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

int N;
int nums[101];
long long dp[101][21];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> nums[i];
	
	dp[1][nums[1]] = 1;
	for (int i = 2; i <= N-1; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			if (dp[i - 1][j])
			{
				if (j + nums[i] <= 20) dp[i][j + nums[i]] += dp[i - 1][j];
				if (j - nums[i] >= 0) dp[i][j - nums[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 1][nums[N]] << endl;

	return 0;
}
