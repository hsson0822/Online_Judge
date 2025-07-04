#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

const int INF = INT_MAX;

class Person
{
public:
    int idx;
    int sx;
    int sy;
    int ex;
    int ey;
    int dist;

    Person()
    {
        idx= 0;
        sx=0;
        sy=0;
        ex=0;
        ey=0;
        dist = INF;
    }

    Person(int idx, int sx, int sy, int ex, int ey)
        : idx(idx), sx(sx), sy(sy), ex(ex), ey(ey)
        {
            dist = abs(sx - ex) + abs(sy - ey);
        }
};

// struct cmp
// {
//     bool operator()(Person& A, Person& B)
//     {
//         if(A.dist == B.dist)
//         {
//             if(A.ex == B.ex)
//             {
//                 if(A.ey == B.ey)
//                     return A.ex < B.ey;

//                 return A.ey < B.ey;
//             }

//             return A.ex < B.ex;
//         }

//         return A.dist < B.dist;

//     }
// };


int N, M, F;
int city[21][21];
//priority_queue<Person, vector<Person>, cmp> dest[21][21];
map<int,Person> destMap;
bool isArrived[401];

bool visited[21][21];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pair<int,int> taxi;
int lose;

int personCnt{};

int findPerson()
{
    memset(visited, false, sizeof(visited));

    //cout << "Start : "<< taxi.first << " " << taxi.second << endl;

    queue<tuple<int,int,int>> Q;
    Q.push({taxi.first, taxi.second, 0});
    visited[taxi.first][taxi.second] = true;

    int idx = -1;
    int dist = INF;

    while(!Q.empty())
    {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int f = get<2>(Q.front());
        Q.pop();

        //cout << "Visiting: " << x << " " << y << " " << f << endl;

        if(city[x][y] > 0 && city[x][y] != INF && idx != city[x][y] && !isArrived[city[x][y]])
        {
            //cout << "Found person: " << city[x][y] << " : " << x << " " << y << " " <<f << endl;

            if(dist == INF)
            {
                idx = city[x][y];
                dist = f;
            }
            else
            {
                if(f < dist)
                {
                    idx = city[x][y];
                    dist = f;
                }
                else if(f == dist)
                {
                    //cout<<"Comparing: " << idx << " with " << city[x][y] << endl;
                    if(destMap[idx].sx > x)
                    {
                        idx = city[x][y];
                        dist = f;
                    }
                    else if(destMap[idx].sx == x && destMap[idx].sy > y)
                    {
                        idx = city[x][y];
                        dist = f;
                    }
                }
            }
        }

        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > N || visited[nx][ny] || city[nx][ny] == INF)
                continue;

            visited[nx][ny] = true;
            Q.push({nx, ny, f+1});
        }
    }


    if(idx != -1)
    {
        taxi = {destMap[idx].sx, destMap[idx].sy};
        F -= dist;
    }

    return idx;
}

bool findDest(pair<int,int> d)
{
    memset(visited, false, sizeof(visited));

    queue<tuple<int,int,int>> Q;
    Q.push({taxi.first, taxi.second, 0});
    visited[taxi.first][taxi.second] = true;

    while(!Q.empty())
    {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int f = get<2>(Q.front());
        Q.pop();

        if(x == d.first && y == d.second)
        {
            //cout << "Reached destination: " << x << " " << y << endl;
            taxi = {x, y};
            F -= f;
            lose += f;
            return true;
        }

        for(int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > N || visited[nx][ny] || city[nx][ny] == INF)
                continue;

            visited[nx][ny] = true;
            Q.push({nx, ny, f+1});
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin  >>N >>M >>F;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j =1 ; j <= N ; ++j)
        {
            cin >> city[i][j];

            if(city[i][j] == 1)
                city[i][j] = INF;
        }
    }

    cin >> taxi.first >> taxi.second;

    for(int i = 1 ; i <= M ; ++i)
    {
        int sx,sy, ex,ey;
        cin >> sx >> sy >> ex >> ey;
        //dest[sx][sy].push({sx,sy,ex,ey});

        city[sx][sy] = i;
        destMap[i] = Person(i, sx, sy, ex, ey);
    }
    personCnt = M;

    while(true)
    {
        lose = 0;

        //cout << nextP.idx << endl;
        // cout <<"Fuel Before : " << F << endl;
        int idx = findPerson();
        //cout <<idx<<endl;
        if(idx == -1)
        {
            cout << -1 << endl;
            return 0;
        }

        if(F < 0)
        {
            cout << -1 << endl;
            return 0;
        }

        if(!findDest({destMap[idx].ex, destMap[idx].ey}))
        {
            cout << -1 << endl;
            return 0;
        }

        isArrived[idx] = true;
        --personCnt;

        //cout <<"Lose After : " << F <<endl;
        
        if(F < 0)
        {
            cout << -1 << endl;
            return 0;
        }

        F += lose*2;

        if(personCnt == 0)
        {
            cout << F << endl;
            return 0;
        }
        
        if(F <= 0)
        {
            cout << -1 << endl;
            return 0;
        }

    }
    
    return 0;   
    
} 