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

int dp[10001];
vector<int> coins;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	for(int t= 0 ; t < T; ++t)
	{
		int N;
		cin >> N;

		coins.clear();

		for(int i = 0 ; i < N ; ++i)
		{
			int c;
			cin >> c;

			coins.push_back(c);
		}

		int M;
		cin >> M;

		memset(dp, 0, sizeof(dp));

		dp[0] = 1;
		for(int c : coins)
		{
			for(int i = c; i <= M ; ++i)
			{
				dp[i] += dp[i-c];
			}
		}
		
		cout << dp[M] << "\n";
	}

	return 0;
}