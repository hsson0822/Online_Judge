#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> sta;
    
    for(char& ch : s)
    {
        if(!sta.empty())
        {
            if(sta.top() == ch)
                sta.pop();
            else
                sta.push(ch);
        }
        else
            sta.push(ch);
            
    }

    return sta.empty()?1:0;
}