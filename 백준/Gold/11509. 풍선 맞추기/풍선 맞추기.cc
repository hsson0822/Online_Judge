#include <iostream>
#include <vector>

using namespace std;

int arrow[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> nums(N);

	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	int answer{};
	for (int i = 0; i < N; ++i)
	{
		if (arrow[nums[i]] == 0)
		{
			++arrow[nums[i] - 1];
			++answer;
			continue;
		}

		--arrow[nums[i]];
		++arrow[nums[i] - 1];
	}

	cout << answer;

	return 0;
}
