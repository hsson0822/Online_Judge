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
int M;
int arr[1001][1001];
int dp[1001][1001];
int big{};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			char ch;
			cin >> ch;
			arr[i][j] = ch-'0';
			
			if (arr[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				big = max(big, dp[i][j]);
			}

			//for (int a = 1; a <= N; ++a)
			//{
			//	for (int b = 1; b <= M; ++b)
			//	{
			//		cout << dp[a][b] << " ";
			//	}
			//	cout << endl;
			//}
			//cout << endl;
		}
	}
	
	cout << pow(big, 2);

	return 0;
}
