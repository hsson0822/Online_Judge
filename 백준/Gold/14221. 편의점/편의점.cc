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
vector<pair<int, int>> city[5001];
queue<int> peon;

int costs[5001];
const int INF = INT_MAX;

struct cmp
{
	bool operator()(pair<int, int> A, pair<int, int> B)
	{
		if (A.second == B.second)
			return A.first > B.first;

		return A.second < B.second;
	}
};

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> PQ;
	fill_n(costs, N + 1, INF);

	while (!peon.empty())
	{
		int start = peon.front();
		peon.pop();

		PQ.push({ start,0 });
		costs[start] = 0;
	}

	while (!PQ.empty())
	{
		int cur = PQ.top().first;
		int cost = PQ.top().second;
		PQ.pop();

		if (costs[cur] < cost) continue;

		for (int i = 0; i < city[cur].size(); ++i)
		{
			int next = city[cur][i].first;
			int nCost = city[cur][i].second;

			if (costs[next] > cost + nCost)
			{
				costs[next] = cost + nCost;
				PQ.push({ next, costs[next] });
			}
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
		int w;
		cin >> a >> b >> w;

		city[a].push_back({ b,w });
		city[b].push_back({ a,w });
	}

	vector<int> house;
	
	int P;
	int Q;
	cin >> P >> Q;

	for (int i = 0; i < P; ++i)
	{
		int a;
		cin >> a;
		house.push_back(a);
	}

	for (int i = 0; i < Q; ++i)
	{
		int a;
		cin >> a;
		peon.push(a);
	}

	//priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> PQ;
	dijkstra();

	/*for (int i = 1; i <= N; ++i)
		cout << costs[i] << " ";
	cout << endl;*/

	/*for (int i = 0; i < P; ++i)
	{
		PQ.push({ house[i], costs[house[i]] });
	}*/

	int houseNum{};
	int len = INT_MAX;

	for (int i = 0; i < P; ++i)
	{
		int h = house[i];

		if (len > costs[h])
		{
			houseNum = h;
			len = costs[h];
		}
		else if (len == costs[h])
		{
			if (houseNum > h)
				houseNum = h;
		}
	}
	cout << houseNum;

	/*while (!PQ.empty())
	{
		int cur = PQ.top().first;
		int cost = PQ.top().second;
		PQ.pop();

		cout << cur << " : " << cost << endl;
	}*/

	//cout << PQ.top().first;

	return 0;
}
