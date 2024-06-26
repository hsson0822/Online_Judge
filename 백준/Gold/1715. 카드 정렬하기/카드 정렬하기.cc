#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<long long,vector<long long>, greater<long long>> PQ;

	for (int i = 0; i < N; ++i)
	{
		long long k;
		cin >> k;
		PQ.push(k);
	}

	long long sum{};
	while (PQ.size() != 1)
	{
		long long s{};
		long long n = PQ.top();
		PQ.pop();
		
		long long m = PQ.top();
		PQ.pop();
		
		s += n + m;
		PQ.push(s);
		sum += s;
	}

	cout << sum;

	return 0;
}