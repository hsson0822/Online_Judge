#include <iostream>
#include <algorithm>

using namespace std;

int pre[1001];
int mid[1001];

void tree(int preBegin, int preEnd, int midBegin, int midEnd)
{
	auto it = find(mid + midBegin, mid + midEnd, pre[preBegin]);
	
	int preSize = distance(mid + midBegin, it);
	int postSize = distance(it+1, mid + midEnd);
	
	if (preSize != 0)
	{
		tree(preBegin + 1,
			preBegin + preSize + 1,
			midBegin,
			midBegin + preSize);
	}
	if(postSize != 0)
	{
		tree(preBegin + preSize + 1,
			preBegin + preSize + 1 + postSize,
			midBegin + preSize + 1,
			midBegin + preSize + 1 + postSize);
	}

	cout << pre[preBegin] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{
		int K;
		cin >> K;

		for (int i = 0; i < K; ++i)
		{
			int n;
			cin >> n;
			pre[i] = n;
		}

		for (int i = 0; i < K; ++i)
		{
			int n;
			cin >> n;
			mid[i] = n;
		}

		tree(0, K, 0, K);
		cout << endl;
	}

	return 0;
}