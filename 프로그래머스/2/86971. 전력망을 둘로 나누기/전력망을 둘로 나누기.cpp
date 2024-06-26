#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> graph[101];
int cnt;

void bfs(int v1, int v2)
{
    queue<int> Q;
    Q.push(v1);

    vector<bool> visited(101);
    visited[v1] = true;
    visited[v2] = true;
    
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        
        for(int i = 0 ; i < graph[k].size() ; ++i)
        {
            if(visited[graph[k][i]]) continue;
            
            Q.push(graph[k][i]);
            ++cnt;
            visited[graph[k][i]] = true;
        }
        
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    int bigger{};
    
    for(int i = 0 ; i < wires.size() ; ++i)
    {
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i = 0 ; i < wires.size() ; ++i)
    {
        cnt = 1;
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        
        bfs(v1, v2);
        answer = min(answer, abs(2 * cnt - n));
    }
    
    return answer;
}