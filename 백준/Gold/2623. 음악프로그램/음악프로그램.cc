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

queue<int> singList;
queue<int> graph[1001];
int degree[1001];
queue<int> answer;

void topological()
{
	while (!singList.empty())
	{
		int cur = singList.front();
		singList.pop();

		answer.push(cur);

		int size = graph[cur].size();
		for(int i = 0 ; i < size ; ++i)
		{
			int n = graph[cur].front();
			graph[cur].pop();
			--degree[n];

			if (degree[n] == 0)
				singList.push(n);
			else
				graph[cur].push(n);
		}

	}
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= M; ++i)
	{
		int n;
		cin >> n;

		int before{};

		for (int j = 0; j < n; ++j)
		{
			int s;
			cin >> s;

			if(before==0)
			{
				before = s;
			}
			else
			{
				graph[before].push(s);
				++degree[s];
				before = s;
			}

		}
	}

	/*for (int i = 1; i <= N; ++i)
	{
		cout << i << " : ";
		while (!graph[i].empty())
		{
			cout << graph[i].front()<< ", " ;
			graph[i].pop();
		}
		cout << endl;
	}

	return 0;
	*/


	for (int i = 1; i <= N; ++i)
	{
		if (degree[i] == 0)
			singList.push(i);
	}

	if (singList.size() == 0)
	{
		cout << 0;
		return 0;
	}

	topological();

	if (answer.size() != N)
	{
		cout << 0;
		return 0;
	}

	while (!answer.empty())
	{
		cout << answer.front() << "\n";
		answer.pop();
	}

	return 0;
}
