#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    priority_queue<long long, vector<long long>, less<long long>> device;

    for (int i = 0; i < N; ++i)
    {
        long long n;
        cin >> n;
        device.push(n);
    }

    priority_queue<long long, vector<long long>, greater<long long>> PQ;
    while (PQ.size() < M && !device.empty())
    {
        PQ.push(device.top());
        device.pop();
    }

    while (!device.empty())
    {
        long long end_time = PQ.top();
        PQ.pop();
        end_time += device.top();
        device.pop();
        PQ.push(end_time);
    }

    long long time = 0;
    while (!PQ.empty())
    {
        time = max(time, PQ.top());
        PQ.pop();
    }

    cout << time;

    return 0;
}
