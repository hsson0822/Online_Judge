#include <bits/stdc++.h>

using namespace std;

vector<int> houses;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, C;
	cin >> N >> C;

	for(int i = 0 ; i < N ; ++i)
	{
		int n;
		cin >> n;
		houses.push_back(n);
	}

	sort(houses.begin(), houses.end());

	int start = 1;
	int end = houses[N-1] - houses[0];
	int result{};

	while(start <= end)
	{
		int mid = (start+end) / 2;

		int cnt = 1;
		int prev = houses[0];

		for(int i = 1; i < N ; ++i)
		{
			if(houses[i] - prev >= mid)
			{
				++cnt;
				prev = houses[i];
			}
		}

		if(cnt >= C)
		{
			result = max(result,mid);
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}

	cout << result;

	return 0;
}


/*

*/