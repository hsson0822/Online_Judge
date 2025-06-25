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

int N, M, X;
int visited[100001];
vector<int> downGraph[100001];
vector<int> upGraph[100001];

int childCnt = -1;
int parentCnt = -1;



void dfs(int cur)
{
	if (visited[cur])
		return;

	visited[cur] = true;
	++childCnt;

	for (int next : downGraph[cur])
		dfs(next);
}

void rev(int cur)
{
	if (visited[cur])
		return;

	visited[cur] = true;
	++parentCnt;

	for (int next : upGraph[cur])
		rev(next);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		downGraph[a].push_back(b);
		upGraph[b].push_back(a);
	}

	dfs(X);

	memset(visited, false, sizeof(visited));

	rev(X);

	cout << parentCnt + 1 << " " << N - childCnt;
	
	return 0;
}
