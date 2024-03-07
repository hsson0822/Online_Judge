#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 6; ++i)
	{
		int k;
		cin >> k;
		nums.push_back(k);
	}

	for (int i = -999; i <= 999; ++i)
	{
		bool flag = false;
		for (int j = -999; j <= 999; ++j)
		{
			if ((nums[0] * i + nums[1] * j == nums[2]) && (nums[3] * i + nums[4] * j == nums[5]))
			{
				cout << i << " " << j;
				return 0;
			}
		}
	}

	return 0;
}