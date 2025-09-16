#include <bits/stdc++.h>

using namespace std;

int N, M, D, E;
int height[100001];
long long costsUp[100001];
long long costsDown[100001];
vector<pair<int,long long>> graph[100001];

void DijkUp()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    PQ.push({0,1});
    costsUp[1] = 0;

    while(!PQ.empty())
    {
        int now = PQ.top().second;
        long long cost = PQ.top().first;
        PQ.pop();

        if (cost != costsUp[now]) continue;

        for(int i = 0; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].first;
            long long nCost = graph[now][i].second;

            if(height[now] < height[next])
            {
                if(cost + nCost < costsUp[next])
                {
                    costsUp[next] = cost + nCost;
                    PQ.push({costsUp[next], next});
                }
            }
        }
    }    
}

void DijkDown()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    PQ.push({0, N});
    costsDown[N] = 0;

    while(!PQ.empty())
    {
        int now = PQ.top().second;
        long long cost = PQ.top().first;
        PQ.pop();

        if (cost != costsDown[now]) continue;

        for(int i = 0; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].first;
            long long nCost = graph[now][i].second;

            if(height[now] < height[next])
            {
                if(cost+nCost < costsDown[next])
                {   
                    costsDown[next] = cost + nCost;
                    PQ.push({costsDown[next], next});
                }
            }
        }
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D >> E;
    
    for(int i =1 ; i <= N ; ++i)
    {
        cin >> height[i];

        costsUp[i] = LLONG_MAX;
        costsDown[i] = LLONG_MAX;
    }
    
    for(int i = 0 ; i < M ; ++i)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    
    DijkUp();
    DijkDown();

    long long answer = LLONG_MIN;
    for(int i = 2; i < N ; ++i)
    {
        if(costsUp[i] == LLONG_MAX || costsDown[i] == LLONG_MAX) continue;

        long long acc = 1LL * height[i] * E;
        long long health = 1LL * (costsUp[i] + costsDown[i]) * D;

        answer = max(answer, acc-health);

        // if(answer < E*height[i] - D * (costsUp[i] +costsDown[i]))
        // {
        //     answer = E*height[i] - D * (costsUp[i] +costsDown[i]);
        // }
    }

    if(answer == LLONG_MIN)
        cout <<"Impossible";
    else
        cout <<answer;

    return 0;
}
