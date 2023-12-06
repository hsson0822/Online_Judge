#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int time = 1;
    
    while (storey != 0)
    {
        int r = pow(10, time);

        int remain = storey % r;
        for (int i = 1; i < time; ++i)
            remain /= 10;
        
        if (remain < 5)
        {
            answer += remain;
            storey -= remain * pow(10, time - 1);
        }
        else if (remain == 5)
        {
            int k = pow(10, time+1);
            int j = storey / r;
            j %= 10;

            if (j >= 5)
            {
                answer += (10 - remain);
                storey += (10 - remain) * pow(10, time - 1);
            }
            else
            {
                answer += remain;
                storey -= remain * pow(10, time - 1);
            }
        }
        else
        {
            answer += (10 - remain);
            storey += (10 - remain) * pow(10, time - 1);
        }
        
        ++time;
    }
    
    return answer;
}