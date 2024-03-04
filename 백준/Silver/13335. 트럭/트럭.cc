#include <iostream>
#include <queue>

using namespace std;

int truckCount;
int leng;
int weight;

queue<int> truck;
queue<pair<int, int>> bridge;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> truckCount >> leng >> weight;

	for (int i = 0; i < truckCount; ++i)
	{
		int t;
		cin >> t;
		truck.push(t);
	}

	int now{};
	int cnt=1;

	while (!truck.empty() || !bridge.empty())
	{
		int k = bridge.size();
		for (int i = 0; i < k; ++i)
		{
			auto t = bridge.front();
			bridge.pop();
			--(t.second);

			if (t.second > 0)
				bridge.push(pair(t.first, t.second));
			else
				now -= t.first;
		}

		if (truck.empty() && bridge.empty())
			break;

		if (truck.size() != 0 && bridge.size() < leng)
		{
			int t = truck.front();

			if (now + t <= weight)
			{
				truck.pop();
				now += t;
				bridge.push(pair(t, leng));
			}
		}

		++cnt;
	}

	cout << cnt;

	return 0;
}