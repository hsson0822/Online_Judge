using System;

public class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        int[] arrs = new int[10]{0,1,2,3,4,5,6,7,8,9};
        
        for(int i = 0 ; i < arrs.Length ; ++i)
        {
            if(Array.Find(numbers, element => element == arrs[i] ) == 0)
                answer += arrs[i];
        }
        
        return answer;
    }
}