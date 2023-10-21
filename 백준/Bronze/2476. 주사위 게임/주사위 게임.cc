#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	int max{};

	for (int i = 0; i < count; ++i)
	{
		int first;
		int second;
		int third;
		int money{};

		cin >> first >> second >> third;

		vector<int> nums;
		nums.push_back(first);
		nums.push_back(second);
		nums.push_back(third);

		sort(nums.begin(), nums.end());

		if (nums[0] == nums[1] && nums[1] == nums[2] && nums[0] == nums[2])
		{
			money = 10000 + nums[0] * 1000;
		}
		else if (nums[0] == nums[1] || nums[1] == nums[2])
		{
			money = 1000 + nums[1] * 100;
		}
		else
		{
			money = nums[2] * 100;
		}

		if (max < money)
			max = money;
	}

	cout << max;
}