#include <iostream>

using namespace std;

int score[100001];
int miss[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int sum{};
	for (int i = 1; i <= N; ++i)
	{
		int k;
		cin >> k;
		score[i] = k;

		if (i != 1)
		{
			if (score[i - 1] > score[i])
				++sum;
		}
		miss[i] = sum;
	}

	int Q;
	cin >> Q;

	for (int i = 0; i < Q; ++i)
	{
		int x;
		int y;
		cin >> x >> y;

		cout << miss[y] - miss[x] << "\n";
	}

	return 0;
}