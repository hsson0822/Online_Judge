#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[2][100001];

int solution(vector<int> sticker)
{
    int answer{};
    if (sticker.size() == 1) return sticker[0];
    
    dp[0][0] = sticker[0];
    dp[0][1] = sticker[0];
    
    dp[1][0] = 0;
    dp[1][1] = sticker[1];
    
    for(int i = 2; i < sticker.size() ; ++i)
    {
        dp[0][i] = max(dp[0][i - 2] + sticker[i] , dp[0][i - 1]);
        dp[1][i] = max(dp[1][i - 2] + sticker[i] , dp[1][i - 1]);
    }
    
    return max(dp[0][sticker.size()-2], dp[1][sticker.size()-1]);
}