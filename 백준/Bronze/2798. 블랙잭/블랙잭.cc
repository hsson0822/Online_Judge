#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;

	cin >> N >> M;

	vector<int> nums;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	int max{};

	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			for (int k = j + 1; k < N; ++k)
			{
				int newNum = nums[i] + nums[j] + nums[k];
				if (newNum <= M && newNum > max)
					max = newNum;
			}
		}
	}
	cout << max;

}