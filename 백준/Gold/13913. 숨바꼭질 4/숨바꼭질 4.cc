#include <bits/stdc++.h>

using namespace std;

const int MAX = 200001;

int N, K;
vector<int> parent(MAX,-1);
vector<int> visited(MAX,-1);

void bfs()
{
    queue<int> Q;
    visited[N] = 0;
    Q.push(N);

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if(cur == K)
        {
            vector<int> vec;

            while(cur != -1)
            {
                vec.push_back(cur);
                cur = parent[cur];
            }

            reverse(vec.begin(), vec.end());

            cout << vec.size()-1 << "\n";
            for(auto n : vec)
                cout << n << " ";
            
            return;
        }

        int nexts[] = {cur-1, cur+1, cur*2};
        for(auto next : nexts)
        {
            if(next < 0 || next > MAX) continue;
            if(visited[next] != -1) continue;

            visited[next] = visited[cur]+1;
            parent[next] = cur;
            Q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    bfs();

    return 0;
}