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

class Edge
{
public:
    int a, b, w;

    Edge(int a, int b, int w) : a(a), b(b), w(w) {}

    bool operator<(Edge &e)
    {
        return w < e.w;
    }
};

int N;
int parent[201];

vector<Edge> already;
vector<Edge> need;
vector<pair<int, int>> build;

int cost{};

int getParent(int a)
{
    if (a == parent[a])
        return a;

    return parent[a] = getParent(parent[a]);
}

bool isUnion(int a, int b)
{
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa == pb)
        return false;

    parent[pb] = pa;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int c;
            cin >> c;

            if (i >= j)
                continue;
            

            if (c > 0)
            {
                need.push_back({i, j, c});
            }
            else if (c < 0)
            {
                already.push_back({i, j, -c});
                cost += -c;
            }
        }
    }

    sort(already.begin(), already.end());
    sort(need.begin(), need.end());

    for (int i = 0; i < already.size(); ++i)
    {
        isUnion(already[i].a, already[i].b);
    }

    int cnt{};
    for (int i = 0; i < need.size(); ++i)
    {
        if (isUnion(need[i].a, need[i].b))
        {
            cost += need[i].w;
            ++cnt;
            build.push_back({need[i].a, need[i].b});
        }
    }

    cout << cost << " " << cnt << "\n";
    for (int i = 0; i < build.size(); ++i)
        cout << build[i].first << " " << build[i].second << "\n";
    return 0;
}