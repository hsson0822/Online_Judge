public class Solution {
    public bool solution(int x) {
        bool answer = true;
        string str = x.ToString();
        int sum = 0;
        foreach(char ch in str)
            sum += ch -'0';
        if(x % sum !=0)
            answer = false;
        return answer;
    }
}