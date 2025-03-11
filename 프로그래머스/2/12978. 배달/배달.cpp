#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int>> country[51];
int dist[51];

const int INF = 987654321;

void dijkstra(int start)
{
    priority_queue<pair<int,int>> PQ;
    dist[start] = 0;
    PQ.push({start,0});
    
    while(!PQ.empty())
    {
        int cur = PQ.top().first;
        int cost = PQ.top().second;
        PQ.pop();
        
        if(dist[cur] < cost) continue;
        
        for(int i = 0 ; i < country[cur].size() ; ++i)
        {
            int next = country[cur][i].first;
            int nCost = country[cur][i].second;
            
            if(dist[next] > cost + nCost)
            {
                dist[next] = cost +nCost;
                PQ.push({next,dist[next]});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 0 ; i < road.size() ; ++i)
    {
        int a = road[i][0];
        int b = road[i][1];
        int w = road[i][2];
        country[a].push_back({b,w});
        country[b].push_back({a,w});
    }

    fill_n(dist,51,INF);
    
    dijkstra(1);
    
    for(int i = 1 ; i <= N ; ++i)
    {
        if(dist[i] <= K && dist[i] != INF)
            ++answer;
    }

    return answer;
}