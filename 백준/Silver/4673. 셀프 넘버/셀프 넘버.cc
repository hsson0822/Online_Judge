#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int N =1 ; N <= 10000 ; ++N)
	{
		bool flag = false;

		for (int i = N; i > 0; --i)
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
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << N << "\n";
	}

	return 0;
}