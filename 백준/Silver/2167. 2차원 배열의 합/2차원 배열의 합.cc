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

int arr[301][301];
int sum[301][301];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int M;
	
	cin >> N >> M;

	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int n;
			cin >> n;
			arr[i][j] = n;

			sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i-1][j-1];
		}
	}


	int K;
	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		int x1;
		int y1;
		int x2;
		int y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sum[x2][y2] -sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1] << "\n";
	}
	

	return 0;
}
