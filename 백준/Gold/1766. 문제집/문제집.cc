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

int parent[32001];

//struct cmp
//{
//	bool operator()(int A, int B)
//	{
//		if (parent[A] < parent[B])
//			return true;
//
//		return A > B;
//	}
//};

int N;
int M;
queue<int> ques[32001];
//priority_queue<int, vector<int>, cmp> arr;
//priority_queue<int, vector<int>, greater<int>> arr;
priority_queue<int,vector<int>, greater<int>> arr;
bool visited[32001];

queue<int> answer;

void dfs(int start)
{
	while (!ques[start].empty())
	{
		int next = ques[start].front();
		ques[start].pop();

		if (visited[next]) continue;

		--parent[next];

		if (parent[next] <= 0)
		{
			parent[next] = 0;
			arr.push(next);
		}
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

		ques[a].push(b);
		++parent[b];
		//arr.push(a);
	}

	for (int i = 1; i <= N; ++i)
		arr.push(i);

	while (!arr.empty())
	{
		int n = arr.top();
		arr.pop();

		//cout << "START : " << n << " : " << parent[n] << endl;

		if (visited[n]) continue;
		if (parent[n] != 0)
		{
			//arr.push(n);
			continue;
		}

		dfs(n);
		answer.push(n);
		visited[n] = true;
	}

	while (!answer.empty())
	{
		cout << answer.front() << " ";
		answer.pop();
	}

	return 0;
}
