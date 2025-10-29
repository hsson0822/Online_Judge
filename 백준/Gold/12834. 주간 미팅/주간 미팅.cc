#include <bits/stdc++.h>

using namespace std;

int N, V, E;
int A, B;
int home[101];
vector<pair<int, int>> connect[1001];
int Distance[1001];
priority_queue<pair<int, int>> Q;

void Dijstra(int st)
{
	Distance[st] = 0;
	Q.push({-0, st});
	while(!Q.empty())
    {
		int x = Q.top().second;
		int cost = -Q.top().first;
		Q.pop();

		if(Distance[x] < cost)
            continue;

		for(int i = 0; i < connect[x].size(); i++)
        {
			int next = connect[x][i].first;
			int nCost = cost + connect[x][i].second;
			if(Distance[next] > nCost){
				Distance[next] = nCost;
				Q.push({-Distance[next], next});
			}
		}
	}
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> V >> E;
	cin >> A >> B;

	for(int i = 1; i <= N; i++){
		cin >> home[i];
	}

	for(int i = 1; i <= E; i++){
		int x, y, cost;
		cin >> x >> y >> cost;
		connect[x].push_back({y, cost});
		connect[y].push_back({x, cost});
	}
    
    int sum = 0;
	for(int i = 1; i <= N; i++)
    {	
        for(int i = 1; i <= V; i++)
		    Distance[i] = 1e9;

		Dijstra(home[i]);

		int dis_1, dis_2;
        
		if(Distance[A] == 1e9)
            dis_1 = -1;
		else
            dis_1 = Distance[A];

		if(Distance[B] == 1e9)
            dis_2 = -1;
		else
            dis_2 = Distance[B];

		sum += (dis_1 + dis_2);
	}

	cout << sum;
    
    return 0;
}