#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<char,int> Xmem;
map<char,int> Ymem;

string solution(string X, string Y) {
    string answer = "";
    
    for(int i = 0 ; i < X.size() ; ++i)
        Xmem[X[i]]++;
    
    for(int i = 0 ; i < Y.size() ; ++i)
        Ymem[Y[i]]++;
    
    for(int i = 9 ; i >= 0 ; --i)
    {
        int num = min(Xmem[i+'0'], Ymem[i+'0']);
        for(int j = 0; j < num ; ++j)
            answer += i+'0';
    }
    
    
    
    
    if(answer == "")
        return "-1";
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}