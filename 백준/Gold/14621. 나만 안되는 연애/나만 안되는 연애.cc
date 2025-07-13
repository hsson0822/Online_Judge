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
    int a;
    int b;
    int w;

    Edge(int a, int b, int w) : a(a), b(b), w(w) {}

    bool operator<(Edge &E)
    {
        return w < E.w;
    }
};

int N, M;
char gender[1001];
int parent[1001];
vector<Edge> graph;

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

    parent[pa] = pb;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        cin >> gender[i];
        parent[i] = i;
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        if (a > b)
        {

            int temp = a;
            a = b;
            b = temp;
        }

        if (gender[a] != gender[b])
            graph.push_back({a, b, w});
    }

    sort(graph.begin(), graph.end());

    int answer{};
    int cnt{};
    for (int i = 0; i < graph.size(); ++i)
    {
        if (isUnion(graph[i].a, graph[i].b))
        {
            // cout << graph[i].a << " " << graph[i].b << endl;
            answer += graph[i].w;
            ++cnt;
        }
    }

    // for(int i = 1; i <= N; ++i)
    //     cout << parent[i] << " ";
    // cout << endl;

    if (cnt == N - 1)
        cout << answer;
    else
        cout << -1;

    return 0;
}