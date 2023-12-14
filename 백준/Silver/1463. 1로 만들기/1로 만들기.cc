#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    vector<vector<int>> dp;
	vector<int> vec;
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << dp.size() << endl;
		return 0;
	}

	vec.push_back(n);
	dp.push_back(vec);

	bool flag = false;

	for (int i = 0; i < dp.size(); ++i)
	{
		vector<int> vec;

		for (int j = 0; j < dp[i].size(); ++j)
		{

			int a{};
			int b{};

			if (dp[i][j] % 3 == 0)
			{
				a = dp[i][j] / 3;
				vec.push_back(a);
			}

			if (dp[i][j] % 2 == 0)
			{
				b = dp[i][j] / 2;
				vec.push_back(b);
			}

			int c = dp[i][j] - 1;
			vec.push_back(c);

			if (a == 1 || b == 1 || c == 1)
			{
				flag = true;
				break;
			}
		}

		if (flag)
			break;

		dp.push_back(vec);
	}

	cout << dp.size() << endl;
    return 0;
}