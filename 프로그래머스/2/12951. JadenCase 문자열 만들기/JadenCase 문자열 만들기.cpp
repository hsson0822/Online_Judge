#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> words;

    for(int i = 0 ; i < s.size() ; ++i)
    {
        if(i == 0 && isalpha(s[0]))
        {
            s[0] = toupper(s[0]);
            continue;
        }
        
        if(s[i] == ' ' &&  isalpha(s[i+1]))
        {
           s[i+1] = toupper(s[i+1]);
           i+=1; 
        }
        else
            s[i] = tolower(s[i]);
          
    }
    
    return s;
}