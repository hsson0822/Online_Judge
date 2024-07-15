#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N;
long long K;
map<int, long long> bad;
vector<long long> water;
long long answer;

void bfs()
{
	long cnt{};
	queue<pair<int, long long>> Q;

	for (int i = 0; i < water.size(); ++i)
		Q.push(pair(water[i], 0));

	while (!Q.empty())
	{
		int pos = Q.front().first;
		long long b = Q.front().second;
		Q.pop();


			if (bad[pos - 1] == 0 || bad[pos - 1] > b + 1)
			{
				bad[pos - 1] = b + 1;
				answer += b + 1;
				++cnt;
				Q.push(pair(pos - 1, b + 1));
			}

			if (cnt >= K)
				break;
		


			if (bad[pos + 1] == 0 || bad[pos + 1] > b + 1)
			{
				bad[pos + 1] = b + 1;
				answer += b + 1;
				++cnt;
				Q.push(pair(pos + 1, b + 1));
			}

			if (cnt >= K)
				break;
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;

		water.push_back(a);
		bad[a] = -1;
	}

	bfs();

	cout << answer;

	return 0;
}