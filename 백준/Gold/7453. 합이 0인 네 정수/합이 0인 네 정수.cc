#include <bits/stdc++.h>

using namespace std;

int nums[4][4001];
vector<long long> sums;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < 4 ; ++j)
			cin >> nums[j][i];

	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < N ; ++j)
			sums.push_back(nums[0][i] + nums[1][j]);

	sort(sums.begin(), sums.end());

	long long answer{};
	for(int i = 0 ; i < N ; ++i)
	{
		for(int j = 0 ; j < N ; ++j)
		{
			long long sum = -(nums[2][i] + nums[3][j]);
			long long low = lower_bound(sums.begin(), sums.end(), sum) - sums.begin();
			long long high = upper_bound(sums.begin(), sums.end(), sum) - sums.begin();

			if(sum == sums[low]) 
				answer += (high-low);
		}
	}

	cout << answer;

	return 0;
}