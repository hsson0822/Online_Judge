#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    for(int i = 0 ; i < s.size() ; ++i)
    {
        if(i == 0 && isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
        }
        else if( s[i-1] == ' ' && isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
        }
            
    }
    
    return s;
}