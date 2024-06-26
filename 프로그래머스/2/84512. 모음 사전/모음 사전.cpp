#include <string>
#include <vector>
#include <iostream>

using namespace std;

string correct;
int answer = 0;
char alpha[5]{'A','E','I','O','U'};
string str;

void dfs()
{
    if(str.size() == 5)
        return;
    
    for(int i = 0 ; i < 5 ; ++i)
    {
        str += alpha[i];
        ++answer;
        
        if(correct == str)
            return;
        
        dfs();
        
        if(correct == str)
            return;
        
        str = str.substr(0, str.size()-1);
    }
}

int solution(string word) {
    correct = word;
    
    dfs();
    
    return answer;
}