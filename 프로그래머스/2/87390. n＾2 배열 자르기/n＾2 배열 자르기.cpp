#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, 0);

    int cnt = 0;
    for(long long i = left; i <= right; ++i)
    {
        int A = i / n;
        int B = i % n;
        int Value = 0;
        
        if(A >= B)
        {
            Value = A + 1;     
        }
        else
        {
            Value = (A + 1) + (B - A);     
        }

        answer[cnt] = Value;
        cnt += 1;
        
    }
    return answer;
}