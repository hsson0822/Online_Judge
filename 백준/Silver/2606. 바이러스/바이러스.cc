#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> tree[1001];
bool route[1001];

void dfs(int n)
{
	stack<int> sta;
	sta.push(n);
	route[n] = true;

	int count{};

	while (!sta.empty())
	{
		int x = sta.top();
		sta.pop();

		for (int i = 0; i < tree[x].size(); ++i)
		{
			int y = tree[x][i];

			if (!route[y])
			{
				sta.push(x);
				sta.push(y);

				route[y] = true;

				++count;
				break;
			}
		}
	}

	cout << count << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int computer;
	cin >> computer;

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);

		sort(tree[a].begin(), tree[a].end());
		sort(tree[b].begin(), tree[b].end());
	}

	dfs(1);

	return 0;
}