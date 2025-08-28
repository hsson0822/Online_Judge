#include <bits/stdc++.h>
using namespace std;

string N;
int K;
int answer = -1;

// visited[남은 횟수][숫자]
set<string> visited[11];

void bfs() {
    queue<pair<string, int>> Q;
    Q.push({N, K});
    visited[K].insert(N);

    while (!Q.empty()) {
        auto [n, k] = Q.front();
        Q.pop();

        if (k == 0) {
            answer = max(answer, stoi(n));
            continue;
        }

        int len = n.size();
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (i == 0 && n[j] == '0') continue; // 맨 앞이 0 되면 안됨

                string temp = n;
                swap(temp[i], temp[j]);

                if (visited[k - 1].count(temp)) continue;
                visited[k - 1].insert(temp);
                Q.push({temp, k - 1});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    if (N.size() == 1 || (N.size() == 2 && N[1] == '0')) {
        cout << -1;
        return 0;
    }

    bfs();
    cout << answer;
    return 0;
}
