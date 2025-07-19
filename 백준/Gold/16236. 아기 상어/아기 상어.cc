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

int N;
int sea[21][21];

pair<int, int> babyPos;
int babySize = 2;
int timer;
int eat;

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

pair<int, int> bfs()
{
    queue<tuple<int,int, int>> Q;
    Q.push({babyPos.first, babyPos.second,0});

    bool visited[21][21];
    memset(visited, false, sizeof(visited));
    visited[babyPos.first][babyPos.second] = true;

    pair<int, int> foodPos{};
    int foodLen = INT_MAX;

    while (!Q.empty())
    {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int t = get<2>(Q.front());
        Q.pop();

        if (sea[x][y] != 0 && sea[x][y] < babySize)
        {
            if (foodLen == INT_MAX || foodLen > t)
            {
                foodPos = {x, y};
                foodLen = t;
            }
            else if (foodLen == t)
            {
                if (foodPos.first > x)
                {
                    foodPos = {x, y};
                    foodLen = t;
                }
                else if (foodPos.first == x)
                {
                    if (foodPos.second > y)
                    {
                        foodPos = {x, y};
                        foodLen = t;
                    }
                }
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || ny <= 0 || nx > N || ny > N)
                continue;
            if (sea[nx][ny] > babySize)
                continue;
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            Q.push({nx, ny, t+1});
        }
    }

    if (foodPos.first != 0 && foodPos.second != 0)
    {
        timer += foodLen;
        ++eat;
        sea[foodPos.first][foodPos.second] = 0;
        babyPos = foodPos;
    }

    return foodPos;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> sea[i][j];

            if (sea[i][j] == 9)
            {
                babyPos = {i, j};
                sea[i][j] = 0;
            }
        }
    }

    while (true)
    {
        pair<int, int> pos = bfs();
        //cout <<pos.first << " " << pos.second << endl;
        if(eat == babySize)
        {
            eat = 0;
            ++babySize;
            //cout << "Level Up : " << babySize<<endl;
        }

        if (pos.first == 0 && pos.second == 0)
            break;
    }

    cout << timer;

    return 0;
}