#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int M, P;
int node[1001];
int degree[1001];
vector<int> graph[1001];
map<int,pair<int,int>> nodeCnt;

queue<int> Q;

void reset()
{
    for(int i = 0 ; i <= 1000 ; ++i)
    {
        node[i] = 0;
        degree[i] = 0;
        graph[i].clear();
    }
    
    nodeCnt.clear();

    while(!Q.empty())
        Q.pop();
}

void bfs()
{
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        //cout <<cur << " " << node[cur] <<endl;

        for(int i = 0 ; i < graph[cur].size() ; ++i)
        {
            int next = graph[cur][i];

            --degree[next];
            
            if(node[cur] == nodeCnt[next].first)
            {
                ++nodeCnt[next].second;
            }
            else if(node[cur] > nodeCnt[next].first)
            {
                nodeCnt[next].first = node[cur];
                nodeCnt[next].second = 1;
            }

            if(degree[next] == 0)
            {
                if(nodeCnt[next].second >= 2)
                    node[next] = nodeCnt[next].first+1;
                else
                    node[next] = nodeCnt[next].first;

                Q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int t = 0 ; t < T ; ++t)
    {

        reset();

        int k;
        cin >> k >> M>> P;

        for(int i = 0 ; i < P ; ++i)
        {
            int a, b;
            cin >> a >> b;

            ++degree[b];
            graph[a].push_back(b);
        }

        for(int i = 1; i <= M; ++i)
        {
            if(degree[i] == 0)
            {
                Q.push(i);
                node[i] = 1;
            }
        }

        bfs();

        // for(int i = 1 ; i <= M ; ++i)
        //     cout << node[i] << " ";
        // cout <<endl;

        cout << k << " " << node[M] << "\n";
    }

    return 0;
}