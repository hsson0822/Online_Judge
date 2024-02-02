#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> graph[500001];
int visited[500001];
int cnt;

void dfs(int start)
{
	for (int i = 0; i < graph[start].size(); ++i)
	{
		int x = graph[start][i];

		if (visited[x] == 0)
		{
			visited[x] = visited[start] + 1;
			dfs(x);
		}

		if (graph[start].size() == 1 && start != 1)
			cnt += visited[x];
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N-1; ++i)
	{

		int a;
		int b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	visited[1] = 1;
	dfs(1);

	if (cnt % 2 == 0)
		cout << "No";
	else
		cout << "Yes";
		
	return 0;
}