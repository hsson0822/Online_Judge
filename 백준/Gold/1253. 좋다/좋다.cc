#include <iostream>
#include <algorithm>

using namespace std;

int nums[2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	sort(nums, nums + N);

	int answer{};
	for (int i = 0; i < N; ++i)
	{
		int begin = 0;
		int end = N - 1;
		
		while (end > begin)
		{
			if (end == i)
				--end;
			else if (begin == i)
				++begin;
            
            if (end == begin) break;

			if (nums[end] + nums[begin] == nums[i])
			{
				++answer;
				break;
			}
			else if (nums[end] + nums[begin] > nums[i])
				--end;
			else if (nums[end] + nums[begin] < nums[i])
				++begin;
		}
	}

	cout << answer;

	return 0;
}