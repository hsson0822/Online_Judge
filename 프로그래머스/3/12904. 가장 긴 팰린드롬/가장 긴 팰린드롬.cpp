#include <string>
#include <iostream>

using namespace std;

int solution(string s)
{   
    if(s.size() <= 1) return s.size();
    
    int answer = 1;
    //int N = s.size();
    int N = 2;
    
    //while(N > 1)
    string str{};
    while(N <= s.size())
    {
        int left = 0;
        
        str.clear();
        for(int i = 0 ; i < N ; ++i)
            str += s[i];
        
        while(left+N <= s.size())
        {   
            
            bool flag = true;
            for(int i = 0 ; i <= N/2 ; ++i)
            {
                if(str[i] != str[N-1-i])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                answer = N;
                break;
            }
                
            
            ++left;
            
            str.erase(str.begin());
            str += s[left+N-1];
            
        }
        ++N;
    }
    

    return answer;
}