public class Solution {
    public string solution(string phone_number) {
        char[] answer = phone_number.ToCharArray();
        for(int i = answer.Length - 5 ; i >=0 ; --i)
        {
            answer[i] = '*';
        }
        return new string(answer);
    }
}