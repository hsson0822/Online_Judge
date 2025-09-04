#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> nums;
	int idx = 0;

	int temp;
	cin >> temp;
	nums.push_back(temp);

	for(int i = 1 ; i < N ; ++i)
	{
		cin >> temp;

		if(temp > nums[idx])
		{
			nums.push_back(temp);
			++idx;
		}
		else
		{
			int id = lower_bound(nums.begin(), nums.end(), temp) - nums.begin();

			nums[id] = temp;
		}
	}

	cout << N-nums.size();
	

	return 0;
}