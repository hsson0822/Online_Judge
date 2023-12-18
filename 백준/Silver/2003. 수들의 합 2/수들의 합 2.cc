#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int count;
	cin >> count;

	int x;
	cin >> x;

	vector<int> nums;
	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		nums.push_back(n);
	}

	int left = 0;
	int right = 0;
	int sum = nums[0];
	int answer{};
	while (right < count)
	{
		if (sum < x)
		{
			++right;
			if(right < count)
				sum += nums[right];
		}
		else if (sum == x)
		{
			sum -= nums[left];
			++right;
			++left;
			++answer;

			if (right < count)
				sum += nums[right];
			
		}
		else if (sum > x)
		{
			sum -= nums[left];
			++left;
		}
	}

	cout << answer << endl;
    
    return 0;
}