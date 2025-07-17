#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int test[1001];

struct cmp
{   
    bool operator()(pair<int, int> &A, pair<int, int> &B)
    {
        if (A.second == B.second)
            return A.first < B.first;

        return A.second > B.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> PQ;
    int maxDay{};


    for(int i = 0 ; i < N ; ++i)
    {
        int d, w;
        cin >>d >> w;

        PQ.push({w,d});
        maxDay = max(maxDay, d);
    }

    while(!PQ.empty())
    {
        int w = PQ.top().first;
        int d = PQ.top().second;
        PQ.pop();

        for(int i = d ; i >= 1 ; --i)
        {
            if(test[i] < w)
            {
                PQ.push({test[i],i});
                test[i] = w;
                break;
            }
        }
    }

    int answer{};
    for(int i = 1 ; i <= maxDay ; ++i)
        answer += test[i];

    cout <<answer;

    return 0;
}