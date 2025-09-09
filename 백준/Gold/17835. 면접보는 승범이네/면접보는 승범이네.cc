#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<pair<int,int>> graph[100001];
long long costs[100001];

struct cmp
{
	bool operator()(auto& A, auto& B)
	{
		return A.second > B.second;
	}
};

priority_queue<pair<int,long long>,vector<pair<int,long long>>, cmp> testCity;

void dijkstra()
{
	while(!testCity.empty())
	{
		int cur = testCity.top().first;
		long long cost = testCity.top().second;
		testCity.pop();
		
		// cout << cur << " ," << cost << endl;

		if(costs[cur] < cost) continue;

		for(int i = 0 ; i < graph[cur].size() ; ++i)
		{
			int next = graph[cur][i].first;
			long long nCost = graph[cur][i].second;

			if(costs[next] < cost + nCost) continue;

			costs[next] = cost + nCost;
			testCity.push({next,costs[next]});
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N>> M >> K;

	for(int i = 0 ; i < M ; ++i)
	{
		int a, b , w;
		cin >> a >> b >> w;

		graph[b].push_back({a,w});
		
	}

	fill_n(costs, N+1, LLONG_MAX);

	for(int i = 0 ; i < K ; ++i)
	{
		int n;
		cin >> n;

		testCity.push({n,0});
		costs[n] = 0;
	}
	
	dijkstra();

	long long maxCost{};
	int maxCity{};

	for(int i = 1 ; i <= N ; ++i)
	{
		if(maxCost < costs[i] && costs[i] != INT_MAX)
		{
			maxCost = costs[i];
			maxCity = i;
		}
		//cout << i << " : " << costs[i] << endl;
	}

	cout << maxCity << "\n" << maxCost;

	return 0;
}