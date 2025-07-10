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

struct cmp
{
    bool operator()(pair<int, int> &A, pair<int, int> &B)
    {
        if (A.second == B.second)
            return A.first < B.first;

        return A.second > B.second;
    }
};

int pay[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> PQ;
    int maxDay{};

    for (int i = 0; i < N; ++i)
    {
        int p, d;
        cin >> p >> d;

        PQ.push({p, d});
        maxDay = max(maxDay, d);
    }

    while (!PQ.empty())
    {
        // cout <<PQ.top().first << " " << PQ.top().second<<endl;

        int p = PQ.top().first;
        int d = PQ.top().second;
        PQ.pop();

        for (int i = d; i >= 1; --i)
        {
            if (pay[i] < p)
            {
                PQ.push({pay[i],i});
                pay[i] = p;
                break;
            }
        }
    }

    int answer{};
    for (int i = 1; i <= maxDay; ++i)
    {
        //cout << i << " " << pay[i]<<endl;
        answer += pay[i];
    }
    cout << answer;

    return 0;
}