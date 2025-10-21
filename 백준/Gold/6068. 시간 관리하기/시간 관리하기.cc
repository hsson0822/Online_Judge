#include <bits/stdc++.h>

using namespace std;

int N;

struct Work
{
    int t, e;
};

vector<Work> works;

bool check(int mid)
{
    for(int i = 0 ; i < N ; ++i)
    {
        mid += works[i].t;
        if(mid > works[i].e)
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; ++i)
    {
        int t,e;
        cin >> t >> e;
        works.push_back(Work{t,e});
    }

    sort(&works[0], &works[0]+N, [](Work &A, Work &B)
    {
        return A.e < B.e;
    });

    int s = 0;
    int e = 2'000'000;

    int answer = -1;

    while(s <= e)
    {
        int mid = (s+e)/ 2;

        if(check(mid))
        {
            s = mid + 1;
            answer= mid;
        }
        else
        {
            e = mid -1;
        }
    }

    cout <<answer;
    
    return 0;
}