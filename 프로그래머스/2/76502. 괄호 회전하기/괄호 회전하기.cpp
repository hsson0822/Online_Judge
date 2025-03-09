#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int leng = s.size();
    
    for(int i = 0 ; i < leng ; ++i)
    {

            stack<char> sta;
            for(int j = 0 ; j < s.size() ; ++j)
            {
                if(s[j] == '{' || s[j]=='(' || s[j] =='[')
                    sta.push(s[j]);
                else
                {
                    if(sta.top() == '{' && s[j]=='}')
                        sta.pop();
                    else if(sta.top() == '(' && s[j]==')')
                        sta.pop();
                    else if(sta.top() == '[' && s[j]==']')
                        sta.pop();
                    else
                        sta.push(s[j]);
                }
            }

            if(sta.size() == 0)
                ++answer;
        
        char ch = s[0];
        string newStr = s.substr(1,s.size());
            
        newStr += ch;
        s = newStr;
        
    }
    
    return answer;
}