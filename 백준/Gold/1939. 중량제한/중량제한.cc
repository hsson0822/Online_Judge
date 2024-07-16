#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
int M;
int Start;
int End;
int Max;

vector<pair<int, int>> bridge[10001];
bool visited[10001];

bool bfs(int cost)
{
	queue<int> Q;
	Q.push(Start);
	visited[Start] = true;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		if (cur == End) return true;

		for (int i = 0; i < bridge[cur].size(); ++i)
		{
			int next = bridge[cur][i].first;
			int nCost = bridge[cur][i].second;
			
			if (visited[next] == false && cost <= nCost)
			{
				visited[next] = true;
				Q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		bridge[a].push_back(pair(b, w));
		bridge[b].push_back(pair(a, w));

		Max = max(Max, w);
	}

	cin >> Start >> End;

	int low = 0;
	int high = Max;

	while (low <= high)
	{
		memset(visited, false, sizeof(visited));
		int mid = (low + high) / 2;
		
		if(bfs(mid) == true)
			low = mid+1;
		else
			high = mid -1;

	}
	cout << high;


	return 0;
}