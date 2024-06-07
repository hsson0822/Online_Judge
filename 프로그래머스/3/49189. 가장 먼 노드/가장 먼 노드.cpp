#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[20001];
int dist[20001];
const int INF = 987654321;

void dijkstra()
{
    priority_queue<int> PQ;
    PQ.push(1);
    dist[1] = 0;
    
    while(!PQ.empty())
    {
        int cur = PQ.top();
        PQ.pop();
        
        for(int i = 0 ; i < graph[cur].size() ; ++i)
        {
            int next = graph[cur][i];
            
            if(dist[next] > dist[cur] + 1)
            {
                dist[next] = dist[cur] + 1;       
                PQ.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0 ; i < edge.size() ; ++i)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    for(int i = 1 ; i <= n ; ++i)
        dist[i] = INF;
    
    dijkstra();
    
    int far = *max_element(dist, dist + n+1);
    
    for(int i = 1 ; i <= n ; ++i)
    {
        if(dist[i] == far)
        {
            ++answer;
        }
    }
        
            
    return answer;
}