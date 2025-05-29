#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int N;
int M;
int S;
int E;
vector<int> graph[10001];
bool visited[10001];
int answer{};

void bfs(int s, int e)
{
	queue<pair<int, queue<int>>> Q;
	queue<int> temp;
	Q.push({ s,{} });

	while (!Q.empty())
	{
		int cur = Q.front().first;
		queue<int> que = Q.front().second;
		Q.pop();

		if (cur == e)
		{
			temp = que;
			break;
		}

		//cout << cur << endl;
		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];
			queue<int> tempQ = que;
			tempQ.push(graph[cur][i]);

			if (visited[next]) continue;

			//cout << cur << " " << next << endl;
			visited[next] = true;
			Q.push({ next,tempQ });
		}
	}

	memset(visited, false, sizeof(visited));

	//cout << "end------------"<<endl;

	answer += temp.size();
	while (!temp.empty())
	{
		int n = temp.front();
		temp.pop();

		visited[n] = true;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i)
		sort(graph[i].begin(), graph[i].end());

	cin >> S >> E;

	bfs(S, E);

	//for (int i = 1; i <= N; ++i)
	//{
	//	for (int j = 1; j <= N; ++j)
	//	{
	//		cout << visited[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	bfs(E, S);

	//for (int i = 1; i <= N; ++i)
	//{
	//	for (int j = 1; j <= N; ++j)
	//	{
	//		cout << visited[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << answer;

	return 0;
}
