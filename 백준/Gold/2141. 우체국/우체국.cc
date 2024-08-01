#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<long long, long long > > village;
long long sum[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		long long a;
		long long b;
		cin >> a >> b;
		village.push_back({a,b});
	}

	sort(village.begin(), village.end());
	sum[0] = village[0].second;
	for (int i = 1; i < N; ++i) sum[i] = sum[i - 1] + village[i].second;
	
	long long left = 0;
	long long right = N - 1;
	long long idx = 987654321;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (sum[mid] >= sum[N - 1] - sum[mid])
		{
			right = mid - 1;
			idx = min(idx, village[mid].first);
		}
		else
			left = mid + 1;
	}
	
	cout << idx;

	return 0;
}
