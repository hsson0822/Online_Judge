#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> com[10001];
bool visited[10001];
vector<pair<int,int>> hacking;
int cnt;

void reset()
{
	memset(visited, false, sizeof(visited));
	cnt = 0;
}

void dfs(int n)
{
	visited[n] = true;
	
	for (int i = 0; i < com[n].size(); ++i)
	{
		int x = com[n][i];

		if (!visited[x])
		{
			++cnt;
			dfs(x);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> N >> count;

	for (int i = 0; i < count; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		com[b].push_back(a);
	}

	int bigger{};
	for (int i = 1; i <= N; ++i)
	{
		cnt = 1;
		dfs(i);

		if (bigger < cnt)
		{
			hacking.clear();
			hacking.push_back(pair(i, cnt));
			bigger = cnt;
		}
		else if (bigger == cnt)
			hacking.push_back(pair(i, cnt));
		
		reset();
	}

	for (auto n : hacking)
	{
		cout << n.first << " ";
	}


	return 0;
}