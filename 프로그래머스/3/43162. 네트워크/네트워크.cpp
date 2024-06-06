#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Computer
{
public:
    int a;
    int b;

    Computer(int a, int b) : a(a), b(b) {}


};

vector<Computer> coms;
int parent[201];

int getParent(int a)
{
    if(parent[a] == a) return a;
    
    return parent[a] = getParent(parent[a]);
}

bool isUnion(int a, int b)
{
    int pa = getParent(a);
    int pb = getParent(b);
    
    if(pa == pb) return false;
    
    if(pa < pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
    return true;
    
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            if(i == j) continue;
            if(computers[i][j] == 1)
                    coms.push_back(Computer{i+1, j+1});        
        }
    }
    
    for(int i = 1 ; i <= n ; ++i)
        parent[i] = i;
    
    for(int i = 0 ; i < coms.size() ; ++i)
        isUnion(coms[i].a, coms[i].b);
    
    set<int> cnt;
    for(int i = 1 ; i <= n ; ++i)
    {
        getParent(i);
        cnt.insert(parent[i]);
    }
        
    
    return cnt.size();
}