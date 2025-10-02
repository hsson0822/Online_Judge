#include <bits/stdc++.h>
using namespace std;

void Recul(int from, int mid, int to, int cnt)
{
    if (cnt == 1)
        cout << from << " " << to << "\n";
    else
    {
        Recul(from, to, mid, cnt - 1);
        cout << from << " " << to << "\n";
        Recul(mid, from, to, cnt - 1);
    }
}

string bigPow(int n) {
    string res = "1";
    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = res.size() - 1; j >= 0; j--) {
            int d = (res[j] - '0') * 2 + carry;
            res[j] = (d % 10) + '0';
            carry = d / 10;
        }
        if (carry) res.insert(res.begin(), carry + '0');
    }
    // -1 처리
    int j = res.size() - 1;
    while (res[j] == '0') {
        res[j] = '9';
        j--;
    }
    res[j]--;
    if (res[0] == '0') res.erase(res.begin());
    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cout << bigPow(n) << "\n";

    if (n <= 20)
        Recul(1, 2, 3, n);

    return 0;
}
