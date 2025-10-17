#include <bits/stdc++.h>

using namespace std;

int N, T;
map<pair<int,int>, int> hole;

struct Move
{
    int x, y;
    int t;
};

void bfs()
{
    queue<Move> Q;
    Q.push({0,0,0});
    hole[{0,0}] = 1;

    while(!Q.empty())
    {
        Move cur = Q.front();
        Q.pop();

        if(cur.y == T)
        {
            cout << hole[{cur.x,cur.y}]-1;
            return;
        }

        for(int i = cur.x - 2 ; i <= cur.x + 2; ++i)
        {
            for(int j = cur.y - 2; j <= cur.y + 2 ; ++j)
            {
                if(i < 0 || j < 0 ) continue;
                if(hole[{i,j}] == 0) continue;

                if(hole[{cur.x,cur.y}]+1 < hole[{i,j}])
                {
                    hole[{i,j}] = hole[{cur.x,cur.y}]+1;
                    Q.push({i,j});
                }
            }
        }

    }
    
    cout << -1;
    return;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;

    for(int i = 0 ; i < N ; ++i)
    {
        int a, b;
        cin >> a >> b;
        hole[{a,b}] = 1e9;
    }

    bfs();

    return 0;
}