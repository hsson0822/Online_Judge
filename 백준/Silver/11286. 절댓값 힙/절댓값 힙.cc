#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, compare> que;
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;

		if (x != 0)
			que.push(x);
		else
		{
			if (que.empty())
			{
				cout << 0 << "\n";
				continue;
			}

			cout << que.top() << "\n";
			que.pop();
		}
	}
	
	return 0;
}