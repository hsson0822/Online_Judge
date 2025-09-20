#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int M;
    cin >> str >> M;

    stack<char> left, right;
    for (char c : str) left.push(c);

    while (M--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (cmd == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (cmd == 'B') {
            if (!left.empty()) left.pop();
        } else if (cmd == 'P') {
            char x; cin >> x;
            left.push(x);
        }
    }

    // 왼쪽 스택 → 오른쪽으로 이동시킨 뒤 출력
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
    return 0;
}
