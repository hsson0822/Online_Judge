#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> works(N);
    for (int i = 0; i < N; ++i)
        cin >> works[i].second >> works[i].first;

    sort(works.rbegin(), works.rend());

    int day = works[0].first;
    for (auto &w : works)
    {
        day = min(day, w.first);
        day -= w.second;
    }

    cout << day;

    return 0;
}