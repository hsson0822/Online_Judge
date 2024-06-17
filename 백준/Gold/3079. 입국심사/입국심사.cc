#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
vector<int> judge;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		unsigned long long k;
		cin >> k;
		judge.push_back(k);
	}

	sort(judge.begin(), judge.end());

	unsigned long long min = 1;
	unsigned long long max = M * (unsigned long long)judge.back();
	unsigned long long answer{};

	while (min <= max)
	{
		unsigned long long avg = (min + max) / 2;
		unsigned long long temp{};

		for (int i = 0; i < N; ++i)
		{
			temp += (avg / (unsigned long long)judge[i]);
		}

		if (temp >= M)
		{
			max = avg - 1;
			answer = avg;
		}
		else
			min = avg + 1;
	}

	cout << answer;
	
	return 0;
}