#include <iostream>
#include <vector>

using namespace std;

int N;
int start;
int goal;
vector<int> family[101];
int visited[101];

void dfs(int n)
{
	for (int i = 0; i < family[n].size(); ++i)
	{
		int x = family[n][i];

		if (visited[x] == 0)
		{
			visited[x] = visited[n] + 1;
			dfs(x);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> start >> goal;

	int count;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		family[a].push_back(b);
		family[b].push_back(a);
	}

	visited[start] = 1;
	dfs(start);


		cout << visited[goal]-1;

	return 0;
}