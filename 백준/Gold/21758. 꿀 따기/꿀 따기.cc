#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<long long> honey(N+1), sum(N+1);

    for(int i = 1; i <= N ; ++i)
    {
        cin >> honey[i];
        sum[i] = sum[i-1]+honey[i];
    }

    long long answer{};

    for(int i = 2; i < N ; ++i)
    {
        long long temp = (sum[N] - honey[1]) + (sum[N]-sum[i]) - honey[i];
        answer = max(answer ,temp);
    }

    for(int i =  2; i < N ; ++i)
    {
        long long temp = (sum[N] - honey[N]) + (sum[i-1]) - honey[i];
        answer = max(answer ,temp);
    }

    for(int i = 2; i < N ; ++i)
    {
        long long temp = (sum[i] - honey[1]) + (sum[N-1]) - sum[i-1];
        answer = max(answer ,temp);
    }

    cout << answer;

    return 0;
}
