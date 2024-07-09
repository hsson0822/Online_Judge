#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
int L;
vector<int> road;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> L;

	road.push_back(0);
	road.push_back(L);

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		road.push_back(k);
	}

	sort(road.begin(), road.end());

	int start = 1;
	int end = L - 1;
	int ans = 1000;

	while (end >= start)
	{
		int rest = 0;
		int mid = (start + end) / 2;

		for (int i = 1; i < road.size(); ++i)
		{
			int dist = road[i] - road[i - 1];
			int cnt = dist / mid;

			if (cnt > 0)
			{
				if (dist % mid == 0) rest += cnt - 1;
				else rest += cnt;
			}
		}

		if (rest > M)
			start = mid + 1;
		else
		{
			end = mid - 1;
			ans = min(mid, ans);
		}
	}
	cout << ans;

	return 0;
}