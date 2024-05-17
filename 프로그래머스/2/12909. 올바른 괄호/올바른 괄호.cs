using System;
using System.Collections;

public class Solution {
    public bool solution(string s) {
        bool answer = true;
        Stack stack = new Stack();
        foreach(char ch in s)
        {
            if(ch == '(')
            {
                stack.Push('(');
            }
            else if(ch == ')')
            {
                
                if(stack.Count != 0 && (char)(stack.Peek()) == '(')
                    stack.Pop();
                else
                    stack.Push(')');
            }
        }
        
        if(stack.Count != 0)
            answer = false;
        
        return answer;
    }
}