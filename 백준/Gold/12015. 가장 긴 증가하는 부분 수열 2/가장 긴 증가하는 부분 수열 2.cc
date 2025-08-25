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

	for(int i = 0 ; i < N ; ++i)
	{
		int n;
		cin >> n;
		nums.push_back(n);
	}

	vector<int> answer;
	int cnt = 1;
	answer.push_back(nums[0]);

	for(int i = 1 ; i < N ; ++i)
	{
		if(answer.back() < nums[i])
		{
			answer.push_back(nums[i]);
			++cnt;
		}
		else
		{
			int idx = lower_bound(answer.begin(), answer.end(), nums[i]) - answer.begin();
			
			answer[idx] = nums[i];
		}
	}

	cout << cnt;

	return 0;
}