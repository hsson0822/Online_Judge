#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    string s;
    cin >> N >> s;

    vector<int> cnt(26, 0);
    int distinct = 0;
    int left = 0, answer = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        int cur = s[right] - 'a';
        if (cnt[cur] == 0)
            distinct++;
        cnt[cur]++;

        while (distinct > N) {
            int leftChar = s[left] - 'a';
            cnt[leftChar]--;
            if (cnt[leftChar] == 0)
                distinct--;
            left++;
        }

        answer = max(answer, right - left + 1);
    }

    cout << answer;


    return 0;
}
