#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zero{};
    int time{};
    while(s != "1")
    {
        string temp;
        for(char ch : s)
        {
            if(ch == '1')
                temp += ch;
            else
                ++zero;
        }
        
        s = temp;
        temp = "";
        int size = s.size();
        
        while(size != 0)
        {
            if(size % 2 == 1)
                temp += '1';
            else
                temp += '0';
            
            size /= 2;
            
            if(size == 1)
            {
                temp += '1';
                break;
            }
        }
        
        reverse(temp.begin(), temp.end());
        s = temp;
        cout << s;
        ++time;
    }
    answer.push_back(time);
    answer.push_back(zero);
    return answer;
}