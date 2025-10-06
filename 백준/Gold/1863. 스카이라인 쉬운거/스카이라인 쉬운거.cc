#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    stack<int> st;
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        while (!st.empty() && st.top() > y)
        {
            st.pop();
            answer++;
        }

        if (!st.empty() && st.top() == y) continue;

        if (y > 0)
            st.push(y);
    }

    answer += st.size();

    cout << answer;
    return 0;
}
