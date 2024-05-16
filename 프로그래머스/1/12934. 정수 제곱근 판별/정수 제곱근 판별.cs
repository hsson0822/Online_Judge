using System;

public class Solution {
    public long solution(long n) {
        long answer = -1;
        for(long i = 1 ; i <= Math.Sqrt(n) ; ++i)
        {
            if(n == i * i)
            {
                answer = (i+1)*(i+1);
                break;
            }
                
        }
        return answer;
    }
}