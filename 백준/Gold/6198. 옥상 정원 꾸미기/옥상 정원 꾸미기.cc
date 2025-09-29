#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    stack<long long> sta;
    long long answer{};

    for(int i = 1 ; i <= N ; ++i)
    {
        long long h;
        cin >> h;

        while(!sta.empty() && sta.top() <= h)
        {
            sta.pop();
        }

        answer += sta.size();

        sta.push(h);
    }

    cout << answer;
   
    return 0;
}
