#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int M;
int start;
int goal;

vector<pair<int,int>> tree[1001];
bool visited[1001];
int answer;

void findLength(int start, int goal, int total, int leng)
{
	int answer = total;
	for (int i = 0; i < tree[start].size(); ++i)
	{
		if (tree[start][i].first == goal)
		{
			answer = total + tree[start][i].second;
			cout << answer << '\n';
			return;
		}

		if (!visited[tree[start][i].first])
		{
			visited[tree[start][i].first] = true;
			findLength(tree[start][i].first, goal, total + tree[start][i].second, tree[start][i].second);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N - 1; ++i)
	{
		int A;
		int B;
		int leng;

		cin >> A >> B >> leng;

		tree[A].push_back(pair(B, leng));
		tree[B].push_back(pair(A, leng));
	}
	
	for (int i = 0; i < M; ++i)
	{
		int start;
		int goal;
		cin >> start >> goal;

		visited[start] = true;
		findLength(start, goal, 0, 0);
		
		memset(visited, false, sizeof(visited));
	}

	return 0;
}