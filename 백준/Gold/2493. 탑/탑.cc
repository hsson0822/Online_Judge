#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<pair<long long, long long>> vec;
stack<pair<long long, long long>> sta;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		long long k;
		cin >> k;
		vec.push_back(pair(k, 0));
	}

	for (long long i = vec.size() - 1; i >= 0; --i)
	{
		if (sta.size() == 0)
		{
			sta.push(pair(i, vec[i].first));
			continue;
		}

		while(sta.size() != 0 && sta.top().second <= vec[i].first)
		{
			auto s = sta.top();
			sta.pop();
			vec[s.first].second = i+1;
		}

		sta.push(pair(i, vec[i].first));
	}

	for (auto v : vec)
	{
		cout << v.second << " ";
	}

	return 0;
}