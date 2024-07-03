#include <iostream>

using namespace std;

long long mod[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	long long sum{};
	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		sum += k;
		mod[sum % M]++;
	}

	long long cnt{};
	for (int i = 0; i <= M; ++i)
	{
		cnt += (mod[i] * (mod[i] - 1)) / 2;
	}

	cout << mod[0] + cnt;

	return 0;
}