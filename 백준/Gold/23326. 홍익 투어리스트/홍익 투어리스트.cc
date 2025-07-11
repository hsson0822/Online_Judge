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

int N, Q;
int now{};
map<int,bool> place;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;

    for (int i = 0; i < N; ++i)
    {
        bool b;
        cin >> b;
        if(b)
            place[i] = b;
    }

    for (int i = 0; i < Q; ++i)
    {
        int query;
        cin >> query;

        if (query == 1)
        {
            int n;
            cin >> n;

            if (place[n-1])
                place.erase(n-1);
            else
                place[n-1] = true;
        }
        else if (query == 2)
        {
            int n;
            cin >> n;

            now += n;
            now %= N;

            // cout << "now : " << now << endl;
        }
        else if (query == 3)
        {
            if(place.size() == 0)
                cout << -1<< "\n";
            else
            {
                auto iter = place.lower_bound(now);
                if(iter == place.end())
                {
                    int step = (N-now) + (*place.begin()).first;
                    cout <<step<<"\n";
                }
                else
                    cout << (*iter).first - now << "\n";
            }
        }
    }

    return 0;
}