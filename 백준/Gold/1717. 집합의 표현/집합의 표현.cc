#include <iostream>

using namespace std;

int parent[1000001];

// find 함수 (경로 압축)
int find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

// union 함수
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a; // 그냥 한쪽 루트에 붙임
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 초기화
    for (int i = 0; i <= N; ++i)
        parent[i] = i;

    for (int i = 0; i < M; ++i)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0)
        {
            unite(a, b);
        }
        else
        {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
