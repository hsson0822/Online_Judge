using System.Linq;

public class Solution {
    public long solution(long n) {
        string str = n.ToString();
        str = string.Concat(str.OrderByDescending(ch => ch));
        return long.Parse(str);
    }
}