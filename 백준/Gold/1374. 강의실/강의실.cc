#include <bits/stdc++.h>
using namespace std;

struct Lecture
{
    int id, start, end;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<Lecture> lectures(N);
    for (int i = 0; i < N; ++i)
        cin >> lectures[i].id >> lectures[i].start >> lectures[i].end;

    sort(lectures.begin(), lectures.end(),[](const Lecture &a, const Lecture &b)
         {
             return a.start < b.start;
         });

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(lectures[0].end);

    for (int i = 1; i < N; ++i)
    {
        if (pq.top() <= lectures[i].start)
            pq.pop();

        pq.push(lectures[i].end);
    }

    cout << pq.size();


    return 0;
}
