#include <string>
#include <vector>

using namespace std;

long long dp[2001];

long long solution(int n) {
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i = 4; i <= n ; ++i)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    return dp[n];
}