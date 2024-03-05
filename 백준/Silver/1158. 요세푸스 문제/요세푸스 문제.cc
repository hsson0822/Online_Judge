#include <iostream>
#include <queue>

using namespace std;

int N;
int J;

queue<int> nums;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> J;

	for (int i = 1; i <= N; ++i)
	{
		nums.push(i);
	}

	int cnt{};
	cout << "<";
	while (!nums.empty())
	{
		int k = nums.front();
		nums.pop();
		++cnt;
		
		if (cnt != J)
			nums.push(k);
		else
		{
			cout << k;
			if (!nums.empty())
				cout << ", ";

			cnt = 0;
		}
	}
	cout << ">";

	return 0;
}