#include <bits/stdc++.h>

using namespace std;

int N;
int devel[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0 ; i < N ; ++i)
        cin >> devel[i];

    int left = 0;
    int right = N-1;

    int answer{};
    while(left < right)
    {
        int stat = (right-left-1)*(min(devel[left], devel[right]));
        answer = max(answer, stat);

        if(devel[left] < devel[right])
            ++left;
        else
            --right;
    }
    
    cout << answer;
    
    return 0;
}