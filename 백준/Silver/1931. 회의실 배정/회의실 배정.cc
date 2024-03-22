#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long, long long>> que;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		long long a;
		long long b;
		cin >> a >> b;

		que.push_back(pair(a, b));
	}

	sort(que.begin(), que.end(), [](auto a, auto b)
		{
			return a.first < b.first;
		});

	stable_sort(que.begin(), que.end(), [](auto a, auto b)
		{
			return a.second < b.second;
		});

	int cnt{};
	pair<long long, long long> now{ 0,0 };

	for(int i = 0 ; i < que.size() ; ++i)
	{
		if (que[i].first >= now.second)
		{
			++cnt;
			now.first = que[i].first;
			now.second = que[i].second;
		}
	}

	cout << cnt;

	return 0;
}