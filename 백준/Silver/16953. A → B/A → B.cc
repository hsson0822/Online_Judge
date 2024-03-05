#include <iostream>
#include <queue>

using namespace std;

queue<pair<long long, long long>> num;
long long start;
long long goal;
long long cnt;

void bfs()
{
	while (num.size() != 0)
	{
		auto q = num.front();
		num.pop();

		long long n = q.first * 2;
		if (n == goal)
		{
			cnt = q.second+1;
			break;
		}
		if (n < goal)
			num.push(pair(n, q.second + 1));

		n = stoll(to_string(q.first) + '1');
		if (n < goal)
			num.push(pair(n, q.second + 1));
		if (n == goal)
		{
			cnt = q.second+1;
			break;
		}
	}

	if (cnt == 0)
		cnt = -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> start >> goal;

	num.push(pair(start, 1));

	bfs();

	cout << cnt;

	return 0;
}