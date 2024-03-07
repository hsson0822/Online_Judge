#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		vector<int> nums;
		nums.push_back(i);

		int temp = i;
		while (temp != 0)
		{
			int k = temp % 10;
			nums.push_back(k);
			temp /= 10;
		}

		int num{};
		for (int j = 0; j < nums.size(); ++j)
			num += nums[j];

		if (num == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}