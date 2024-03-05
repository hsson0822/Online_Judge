#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long, long long>> vec;
long long answer = LLONG_MAX;;

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
		vec.push_back(pair(a, b));
	}

	for (int i = 1; i <= N; ++i)
	{
		vector<int> ind;

		for (int j = 0; j < i; ++j)
		{
			ind.push_back(1);
		}

		for (int j = 0; j < N - i; ++j)
		{
			ind.push_back(0);
		}

		sort(ind.begin(), ind.end());

		do
		{
			long long ssin = 1;
			long long sseun{};

			for (int j = 0; j < ind.size(); ++j)
			{
				if (ind[j] == 1)
				{
					ssin *= vec[j].first;
					sseun += vec[j].second;
				}
			}

			long long n = (ssin > sseun) ? (ssin - sseun) : (sseun - ssin);
			if (answer > n)
				answer = n;

		} while (next_permutation(ind.begin(), ind.end()));
	}

	cout << answer;

	return 0;
}