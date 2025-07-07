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

    int x;
    int y;
    int w;

    Edge(int x, int y, int w) : x(x), y(y), w(w) {}

    bool operator<(Edge& e)
    {
        return w < e.w;
    }
    
};

int N, M;
long long K;
vector<Edge> before;
vector<Edge> after;
int parent[1000001];
bool link[1000001];

int getParent(int a)
{
    if( a == parent[a])
    return a;

    return parent[a] = getParent(parent[a]);
}

bool isUnion(int a, int b)
{
    int pa = getParent(a);
    int pb = getParent(b);

    if(pa == pb) return false;

    parent[pb] = pa;
    return true;
}

bool check(int start)
{
    int parent = getParent(start);

    for(int i = start; i <= N ; ++i)
    {
        if(getParent(i) != parent)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N>>M>>K;

    parent[0] = 0;

    for(int i = 1 ; i <= N ; ++i)
    {
        int n;
        cin >> n;

        parent[i] = i;
        after.push_back({i,0,n});

        link[i] = true;
    }

    for(int i = 0 ; i < M ; ++i)
    {
        int a, b;
        cin >> a >> b;

        if (a > b)
        {
            int temp = a;
            a = b;
            b= temp;
        }

        if( a == 1 && b == N)
            link[b] = false;
        else
            link[a] = false;
    }

    
    for(int i = 1; i <= N ; ++i)
    {
        if(link[i] && i != N)
        {
            before.push_back({i,i+1,0});
            after.push_back({i,i+1,0});
        }
        else if(link[i] && i == N)
        {
            before.push_back({i,1,0});
            after.push_back({i,1,0});
        }
    }
    
    sort(before.begin(), before.end());
    
    long long cnt{};
    for(int i = 0 ; i < before.size() ; ++i)
    {
        //cout << before[i].x << " " << before[i].y << " " << graph[i].w << endl;

        if(isUnion(before[i].x, before[i].y))
        {
            //cout << "Add : " << before[i].w<<endl;
            cnt += before[i].w;
        }
    }

    if(cnt <= K && check(1))
    {
        //cout << "A";
        cout << "YES";
        return 0;
    }
   


    for(int i = 0 ; i <= N ; ++i)
        parent[i] = i;

    sort(after.begin(), after.end());

    cnt = 0;
    for(int i = 0 ; i < after.size() ; ++i)
    {
        //cout << after[i].x << " " << after[i].y << " " << graph[i].w << endl;

        if(isUnion(after[i].x, after[i].y))
        {
            //cout << "Add : " << after[i].w<<endl;
            cnt += after[i].w;
        }
    }

    if(cnt <= K && check(0))
    {
        // cout << "B";
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}