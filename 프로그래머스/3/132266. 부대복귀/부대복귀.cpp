#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int INF = 987654321;

vector<int> route[100001];
int dis[100001];

void dijkstra(int start)
{
    queue<pair<int,int>> Q;
    Q.push(pair(start, 0));
    dis[start] = 0;
    
    while(!Q.empty())
    {
        int cur = Q.front().first;
        int cost = Q.front().second;
        Q.pop();
        
        if(dis[cur] < cost) continue;
        
        for(int i = 0 ; i < route[cur].size() ; ++i)
        {
            int next = route[cur][i];
            
            if(dis[next] > cost + 1)
            {
                dis[next] = cost + 1;
                Q.push(pair(next, dis[next]));
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
    for(int i = 0 ; i < roads.size() ; ++i)
    {
        route[roads[i][0]].push_back(roads[i][1]);
        route[roads[i][1]].push_back(roads[i][0]);
        
    }
    
    for(int i = 1 ; i <= n ;++i)
        dis[i] = INF;
        
    dijkstra(destination);
    
    vector<int> answer;
    for(int i = 0 ; i < sources.size() ; ++i)
    {
        if(dis[sources[i]] != INF)
            answer.push_back(dis[sources[i]]);
        else
            answer.push_back(-1);
    }
        
    
    return answer;
}