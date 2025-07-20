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

int R, C;
char board[101][101];
int aduCnt[101][101];

int dx[10]{0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[10]{0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

pair<int, int> jongPos;
queue<pair<int, int>> aduPos;

void jongsoo(int dir)
{
    jongPos.first += dx[dir];
    jongPos.second += dy[dir];
}

void aduino()
{
    int size = aduPos.size();
    // cout << "A " << size << endl;

    for (int i = 0; i < size; ++i)
    {
        int x = aduPos.front().first;
        int y = aduPos.front().second;
        //--aduCnt[x][y];
        aduPos.pop();

        int dir{};
        int len = INT_MAX;

        // cout << "before : " << x << " " << y << endl;

        for (int j = 0; j < 10; ++j)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];

            int l = abs(jongPos.first - nx) + abs(jongPos.second - ny);

            if (len > l)
            {
                dir = j;
                len = l;
            }
        }

        x += dx[dir];
        y += dy[dir];
        //++aduCnt[x][y];
        // cout << "after : " << x << " " << y << endl;
        aduPos.push({x, y});
    }
}

void bomb()
{
    memset(aduCnt, 0, sizeof(aduCnt));

    while(!aduPos.empty())
    {
        int x = aduPos.front().first;
        int y = aduPos.front().second;
        aduPos.pop();

        ++aduCnt[x][y];
    }

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if(aduCnt[i][j] == 1)
            {
                aduPos.push({i,j});
            }
            else
                aduCnt[i][j] = 0;
        }
    }
    

}

bool check()
{
    int size = aduPos.size();

    for(int i = 0 ; i < size ; ++i)
    {
        int x = aduPos.front().first;
        int y = aduPos.front().second;
        aduPos.pop();

        if(jongPos.first == x && jongPos.second == y)
            return true;
        
        aduPos.push({x,y});
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 'I')
            {
                jongPos = {i, j};
                board[i][j] = '.';
            }
            else if (board[i][j] == 'R')
            {
                aduPos.push({i, j});
                board[i][j] = '.';
                ++aduCnt[i][j];
            }
        }
    }

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        jongsoo(str[i] - '0');

        if (check())
        {
            cout << "kraj " << i+1;
            return 0;
        }

        aduino();
        
        if (check())
        {
            cout << "kraj " << i+1;
            return 0;
        }
        
        bomb();
        // for (int i = 1; i <= R; ++i)
        // {
        //     for (int j = 1; j <= C; ++j)
        //     {
        //         if (jongPos.first == i && jongPos.second == j)
        //             cout << 'I';
        //         else if (aduCnt[i][j] > 0)
        //             cout << 'R';
        //         else
        //             cout << '.';
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (jongPos.first == i && jongPos.second == j)
                cout << 'I';
            else if (aduCnt[i][j] > 0)
                cout << 'R';
            else
                cout << '.';
        }
        cout << "\n";
    }

    return 0;
}