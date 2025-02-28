#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define P pair<int,int>

using namespace std;

vector<int> res;
vector<P> graph[50001];
int intensity[50001];
bool isSummit[50001];

void dijkstra(vector<int>& gates)
{
    priority_queue<P, vector<P>, greater<P>> PQ;
    vector<P> temp;
    
    fill(intensity, intensity+50001 , -1);
    
    for(auto s : gates)
    {
        PQ.push(pair(0,s));
        intensity[s] = 0;
    }
    
    while(!PQ.empty())
    {
        int cost = PQ.top().first;
        int cur = PQ.top().second;
        //cout << cost << " " << cur << endl;
        PQ.pop();
        
        if(cost > intensity[cur]) continue;
        
        if(isSummit[cur])
        {
            temp.push_back({cost, cur});
            continue;
        }
        
        for(int i = 0 ; i < graph[cur].size() ; ++i)
        {
            int nCost = graph[cur][i].first;
            int next = graph[cur][i].second;
            
            if(intensity[next] == -1 || max(cost, nCost) < intensity[next])
            {
                intensity[next] = max(cost, nCost);
                PQ.push(pair(intensity[next], next));
            }
        }
    }
    
    sort(temp.begin(), temp.end());
    //cout << temp.size()<<endl;
    res.push_back(temp[0].second);
    res.push_back(temp[0].first);
    //cout << "B : " << temp[0].first << " " << temp[0].second<<endl;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{    
    for(int i = 0 ; i < paths.size() ; ++i)
    {
        int a = paths[i][0];
        int b = paths[i][1];
        int w = paths[i][2];
        
        graph[a].emplace_back(pair(w,b));
        graph[b].emplace_back(pair(w,a));
    }
    
    for(int i = 0 ; i < summits.size() ; ++i)
        isSummit[summits[i]] = true;
    
    dijkstra(gates);
 
    return res;
}