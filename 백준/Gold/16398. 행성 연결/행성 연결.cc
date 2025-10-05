#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int a, b;
    long long w;

    bool operator<(const Node& other) const
    {
        return w < other.w;
    }
};

int N;
vector<Node> graph;
int parent[1001];


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

    parent[pa] = pb;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0 ; i <= N ; ++i)
        parent[i] = i;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= N; ++j)
        {
            int c;
            cin >> c;

            if(c == 0) continue;

            graph.push_back({i,j,(long long)c});
        }
    }

    sort(graph.begin(), graph.end());

    long long answer{};
    for(int i = 0 ; i < graph.size() ; ++i)
    {
        if(isUnion(graph[i].a, graph[i].b))
            answer += graph[i].w;
    }

    cout << answer;

    return 0;
}
