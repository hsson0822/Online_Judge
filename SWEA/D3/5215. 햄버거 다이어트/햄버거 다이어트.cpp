#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int count;
		int limit;
		cin >> count >> limit;

		vector<vector<pair<int, int>>> dp;
		vector<pair<int, int>> v;
		v.push_back(make_pair(0, 0));
		dp.push_back(v);

		for (int i = 0; i < count; ++i)
		{
			vector<pair<int, int>> vec;
			int happy;
			int cal;
			cin >> happy >> cal;
			
			for (int j = 0; j < dp[i].size(); ++j)
			{
				int ha = dp[i][j].first + happy;
				int c = dp[i][j].second + cal;

				vec.push_back(make_pair(ha,c));
				vec.push_back(make_pair(dp[i][j].first, dp[i][j].second));
			}

			dp.push_back(vec);

		}

		int last = dp.size() - 1;
		int maxHappy{};

		for (int i = 0; i < dp[last].size(); ++i)
		{
			if (dp[last][i].second > limit)
				continue;

			if (dp[last][i].first > maxHappy)
				maxHappy = dp[last][i].first;
		}

		cout << "#" << test_case << " " << maxHappy << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}