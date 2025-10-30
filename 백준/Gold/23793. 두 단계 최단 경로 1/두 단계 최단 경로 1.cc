#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int,int>> world[100001];

int start, mid, goal;
int costs[100001];

int answer;

void dijk(int a, int b)
{
    //cout <<a << " -> " << b << endl;
    fill(&costs[0], &costs[0]+N+1, 1e9);

    priority_queue<pair<int,int>> PQ;
    costs[a] = 0;
    PQ.push({0, a});

    while(!PQ.empty())
    {
        int cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();

        //cout << cur << " " << cost<<endl;

        if(costs[cur] < cost) continue;

        for(int i = 0 ; i < world[cur].size() ; ++i)
        {
            int next = world[cur][i].first;
            int nCost = world[cur][i].second;

            if(costs[next] < cost + nCost) continue;

            costs[next] = cost + nCost;
            PQ.push({-costs[next], next});
        }
    }

    if(costs[b] == 1e9)
        answer = -1;
    else
        answer += costs[b];

    //cout << "answer : " << answer<<endl;
}

void direct(int a, int b)
{
    //cout <<a << " -> " << b << endl;
    fill(&costs[0], &costs[0]+N+1, 1e9);

    priority_queue<pair<int,int>> PQ;
    costs[a] = 0;
    PQ.push({0, a});

    while(!PQ.empty())
    {
        int cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();

        //cout << cur << " " << cost<<endl;

        if(costs[cur] < cost) continue;

        for(int i = 0 ; i < world[cur].size() ; ++i)
        {
            int next = world[cur][i].first;
            int nCost = world[cur][i].second;

            if(next == mid) continue;
            if(costs[next] < cost + nCost) continue;

            costs[next] = cost + nCost;
            PQ.push({-costs[next], next});
        }
    }

    if(costs[b] == 1e9)
        answer = -1;
    else
        answer += costs[b];

    //cout << "answer : " << answer<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0 ; i < M ; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        world[a].push_back({b,w});
    }

    cin >> start >> mid >> goal;

    dijk(start, mid);

    if(answer == -1)
        cout << -1 << " ";
    else
    {
        dijk(mid, goal);
        cout << answer << " ";
    }

    answer = 0;
    direct(start,goal);
    cout << answer;
    
    return 0;
}