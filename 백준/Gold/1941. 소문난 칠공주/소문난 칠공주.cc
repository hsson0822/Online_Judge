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

char room[6][6];

int selected[7];

int visited[6][6];
int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

int answer;

bool checkValid()
{
    int r = selected[0] / 5;
    int c = selected[0] % 5;

    queue<pair<int,int>> Q;
    Q.push({r, c});
    int visited2[6][6];
    memset(visited2,0,sizeof(visited2));
    visited2[r][c] = 1;

    int cnt = 1;
    while (!Q.empty())
    {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        for (int i = 0 ; i < 4; ++i)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || visited2[nr][nc] > 0)
                continue;

            visited2[nr][nc] = 1;
            if (visited[nr][nc] > 0)
            {
                cnt++;
                Q.push({nr,nc});
            }
        }
    }

    return cnt == 7;
}

void selectStudent(int start, int cnt, int SCnt, int YCnt)
{
    if (YCnt >= 4)
        return;

    if (cnt == 7 && SCnt >= 4)
    {
        if (checkValid())
        {
            ++answer;
            // System.out.println(Arrays.toString(selected));
        }
        return;
    }

    for (int i = start; i < 25; i++)
    {
        int r = i / 5;
        int c = i % 5;

        if (visited[r][c] > 0)
            continue;

        visited[r][c] = cnt;
        selected[cnt] = i;

        if (room[r][c] == 'S')
            selectStudent(i + 1, cnt + 1, SCnt + 1, YCnt);
        else
            selectStudent(i + 1, cnt + 1, SCnt, YCnt + 1);

        visited[r][c] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> room[i][j];
        }
    }

    selectStudent(0, 0, 0, 0);

    cout << answer;

    return 0;
}
