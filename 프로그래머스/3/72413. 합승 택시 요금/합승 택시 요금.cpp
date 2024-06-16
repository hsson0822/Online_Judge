#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;
vector<pair<int,long long>> graph[201];
long long dist[201];
const int INF = 987654321;

void dijkstra(int start)
{
    for(int i = 1 ; i <= N;  ++i)
    {
        dist[i] = INF;
    }
    
    priority_queue<pair<int, long long>> PQ;
    dist[start] = 0;
    PQ.push(pair(start, 0));
    
    while(!PQ.empty())
    {
        int now = PQ.top().first;
        long long cost = PQ.top().second;
        PQ.pop();
        
        for(int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].first;
            long long nCost = graph[now][i].second;
            
            if(dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost;
                PQ.push(pair(next, dist[next]));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    int answer = 987654321;
    N=n;
    for(int i = 0 ; i < fares.size() ; ++i)
    {
        graph[fares[i][0]].push_back(pair(fares[i][1], fares[i][2]));
        graph[fares[i][1]].push_back(pair(fares[i][0], fares[i][2]));
    }
    
    long long miniest[201];
    long long direct{};
    dijkstra(s);
    direct = dist[a] + dist[b];
    for(int i = 1 ; i <= N ; ++i)
    {
        if(dist[i] == INF) dist[i] = 987654321;
        miniest[i] = dist[i];
    }

    dijkstra(b);
    for(int i = 1 ; i <= N ; ++i)
    {
        if(dist[i] == INF) dist[i] = 987654321;
        miniest[i] += dist[i];
    }

    dijkstra(a);
    for(int i = 1 ; i <= N ; ++i)
    {
        if(dist[i] == INF) dist[i] = 987654321;
        miniest[i] += dist[i];
    }
    
    answer = direct;
    for(int i = 1 ; i <= N ; ++i)
    {
        if(miniest[i] < answer)
            answer = miniest[i];
    }
    
    return answer;
}