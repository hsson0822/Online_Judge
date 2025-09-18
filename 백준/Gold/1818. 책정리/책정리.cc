#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<int> nums;

    cin >> N;

    int n;
    cin >> n;
    nums.push_back(n);

    for(int i = 1 ; i < N ; ++i)
    {
        int num;
        cin >> num;

        if(nums.back() < num)
        {
            nums.push_back(num);
        }
        else
        {
            int idx = lower_bound(nums.begin(), nums.end(), num) - nums.begin();
            nums[idx] = num;
        }
    }

    cout << N-nums.size();

    return 0;
}
