#include <iostream>
#include <algorithm>

using namespace std;

int nums[1000];

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

	int res = 1;
	for (int i = 0; i < N; ++i)
	{
		if (nums[i] > res)
			break;

		res += nums[i];
	}

	cout << res;

	return 0;
}