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

int N;
int sum[2000002];
int arr[2000002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<pair<int,int>> timeRecord;
    vector<int> v;

    for(int i = 0 ; i < N ; ++i)
    {
        int s, e;
        cin >> s >> e;

        timeRecord.push_back({s,e});
        v.push_back(s);
        v.push_back(e);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for(int i = 0 ; i < timeRecord.size() ; ++i)
    {
        sum[lower_bound(v.begin(), v.end(), timeRecord[i].first)-v.begin()] += 1;
        sum[lower_bound(v.begin(), v.end(), timeRecord[i].second)-v.begin()] -= 1;
    }

    for(int i = 1 ; i < v.size() ; ++i)
        sum[i] += sum[i-1];

    int maxN {};
    for(int i = 0 ; i < v.size() ; ++i)
        maxN = max(maxN, sum[i]);

    int Te{}, Tx{};
    for(int i = 0 ; i < v.size() ; ++i)
    {
        if(Tx ==0 && sum[i] == maxN)
        {
            Te = v[i];
            Tx = -1;
        }

        if(Tx == -1 && sum[i] != maxN)
        {
            Tx = v[i];
            break;
        }
    }

    cout << maxN << "\n";
    cout << Te << " " << Tx;

    return 0;
}