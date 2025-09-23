#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    for (int t = 0; t < testCase; ++t)
    {
        multiset<int> sets;

        int K;
        cin >> K;

        int cnt{};

        for (int i = 0; i < K; ++i)
        {
            char C;
            long long N;
            cin >> C >> N;

            if (C == 'I')
            {
                sets.insert(N);
            }
            else
            {
                if (N == -1 && sets.size() != 0)
                {
                    sets.erase(sets.begin());
                }
                else if (N == 1 && sets.size() != 0)
                {
                    sets.erase(prev(sets.end()));
                }
            }
        }

        if (sets.size() != 0)
            cout << *sets.rbegin() << " " << *sets.begin() << "\n";
        else
            cout << "EMPTY\n";
    }

    return 0;
}