#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{   
    int pCnt{};
    int yCnt{};
    
    for(char& ch : s)
    {
        ch = tolower(ch);
        if(ch == 'p')
            ++pCnt;
        else if(ch =='y')
            ++yCnt;
    }

    return pCnt == yCnt;
}