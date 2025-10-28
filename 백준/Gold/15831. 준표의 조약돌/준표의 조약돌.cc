#include <bits/stdc++.h>

using namespace std;

int N,B,W;
const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B >> W;

    string s;
    cin >> s;

    int left{};
    int right{};
    int bCnt{};
    int wCnt{};

    int answer{};
    while(left < N)
    {
        if(right < N && s[right++] == 'W')
            ++wCnt;
        else
            ++bCnt;

        if( bCnt <= B && wCnt >= W)
        {
            answer = max(answer, right - left);
        }
        else if(bCnt > B)
        {
            if(s[left++] =='W')
                --wCnt;
            else
                --bCnt;
        }
    }

    cout <<answer;

    return 0;
}