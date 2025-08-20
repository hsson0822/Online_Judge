#include <bits/stdc++.h>

using namespace std;

struct cmp
{
	bool operator()(auto& A, auto& B)
	{
		if(A.second == B.second)
			return A.first > B.first;

		return A.second > B.second;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> PQ;

	for(int i = 0 ; i < N ; ++i)
	{
		long long a;
		long long b;
		cin >> a >> b;
		PQ.push({a,b});
	}

	int cnt{};
	pair<long long, long long> now{0,0};

	while(!PQ.empty())
	{
		long long a = PQ.top().first;
		long long b = PQ.top().second;
		PQ.pop();

		if(a >= now.second)
		{
			++cnt;
			now.first = a;
			now.second = b;
		}
	}

	cout << cnt;

	return 0;
}