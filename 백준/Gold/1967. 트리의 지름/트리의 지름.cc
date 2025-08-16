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

const int INF = 987654321;

vector<pair<int,int>> graph[10001];
bool visited[10001];
int result;
int endPoint;

void dfs(int cur, int len)
{
	if(visited[cur]) return;

	visited[cur] = true;

	if(result < len)
	{
		result = len;
		endPoint = cur;
	}

	for(int i = 0 ; i <graph[cur].size() ; ++i)
	{
		dfs(graph[cur][i].first, len + graph[cur][i].second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N-1; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}

	dfs(1,0);

	result = 0;
	memset(visited,false, sizeof(visited));

	dfs(endPoint, 0);
	cout << result;

	return 0;
}