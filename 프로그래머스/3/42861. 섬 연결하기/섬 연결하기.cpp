#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Edge
{
public:
    int a;
    int b;
    int w;
    
    Edge(int a, int b, int w ) : a(a), b(b), w(w)
    {
        
    }
};

vector<Edge> islands;
int parent[101];

int getParent(int a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = getParent(parent[a]);
}

bool isUnion(int a, int b)
{
    int na = getParent(a);
    int nb = getParent(b);
    
    if(na == nb) return false;
    
    parent[na] = nb;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i =0 ; i < costs.size() ; ++i)
    {
        islands.push_back(Edge(costs[i][0], costs[i][1], costs[i][2]));
    }
    
    for(int i =0 ; i < n; ++i)
    {
        parent[i] = i;
    }
    
    sort(islands.begin(), islands.end(), [](auto& a, auto& b)
         {
             return a.w < b.w;
         });
    
    for(int i = 0 ; i < islands.size() ; ++i)
    {
        if(isUnion(islands[i].a, islands[i].b))
            answer += islands[i].w;
    }
    
    return answer;
}