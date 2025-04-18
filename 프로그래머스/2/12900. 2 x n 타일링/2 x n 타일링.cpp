#include <string>
#include <vector>

using namespace std;

int dp[60001];

int solution(int n) {
    int answer = 0;
    
    dp[0] = 0;
    dp[1] = 1;
    
    if(n >= 2)
        dp[2] = 2;
    
    for(int i = 3 ; i <= n ; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1000000007;
    }
    
    return dp[n];
}