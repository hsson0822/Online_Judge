#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
   int count;
	cin >> count;

	vector<int> nums;
	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end());
	int answer{};

	int x;
	cin >> x;

	int left = 0;
	int right = count - 1;
	while (left < right)
	{
		int n = nums[left] + nums[right];

		if (n == x)
		{
			++answer;
			++left;
			--right;
		}
		else if (n < x)
		{
			++left;
		}
		else if (n > x)
		{
			--right;
		}
	}

	cout << answer << endl;
    
    return 0;
}