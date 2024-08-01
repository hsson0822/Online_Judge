#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{


		priority_queue<long long,vector<long long>, greater<long long>> Q;

		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			long long n;
			cin >> n;
			Q.push(n);
		}

		long long sum{};
		while (Q.size() != 1)
		{
			long long a;
			long long b;
			a = Q.top();
			Q.pop();
			b = Q.top();
			Q.pop();

			long long add = a + b;
			sum += add;

			Q.push(add);
		}

		cout << sum<< "\n";
	}

	return 0;
}
