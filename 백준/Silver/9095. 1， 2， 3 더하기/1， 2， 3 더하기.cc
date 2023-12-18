#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int count;
	cin >> count;

	for (int k = 0; k < count; ++k)
	{
		int num;
		cin >> num;

		vector<vector<int>> dp;
		vector<int> vec;
		vec.push_back(0);
		dp.push_back(vec);

		for (int i = 0; i < dp.size(); ++i)
		{
			vector<int> vec;
			for (int j = 0; j < dp[i].size(); ++j)
			{
				if (dp[i][j] >= num)
				{
					vec.push_back(dp[i][j]);
					continue;
				}

				vec.push_back(dp[i][j] + 1);
				vec.push_back(dp[i][j] + 2);
				vec.push_back(dp[i][j] + 3);
			}

			dp.push_back(vec);

			if(i != 0)
				if (dp[i].size() == dp[i - 1].size())
					break;
		}

		int answer{};
		for (int i : dp[dp.size() - 1])
		{
			if (i == num)
				++answer;
		}
		cout << answer << endl;
	}
    
    return 0;
}