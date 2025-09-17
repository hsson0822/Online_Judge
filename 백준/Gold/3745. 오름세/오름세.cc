#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	while(cin >> N)
	{
		vector<int> nums;

		for(int i = 0 ; i < N ; ++i)
		{
			int num;
			cin >> num;
			nums.push_back(num);
		}

		vector<int> temp;
		temp.push_back(nums[0]);

		for(int i = 1 ; i < N ; ++i)
		{
			if(temp.back() < nums[i])
			{
				temp.push_back(nums[i]);
			}
			else
			{

				int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
				temp[idx] = nums[i];
			}
		}

		cout << temp.size() << "\n";
	}

	return 0;
}