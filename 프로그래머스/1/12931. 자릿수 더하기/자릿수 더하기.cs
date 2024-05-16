using System;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        string str = n.ToString();
        foreach(char ch in str)
        {
            answer += ch - '0';
        }
        return answer;
    }
}