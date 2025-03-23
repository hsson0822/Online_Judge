#include <string>
#include <vector>

using namespace std;

bool isBab(string str)
{
    bool say[4]{false,false,false,false};
    string s;
    for(char ch : str)
    {
        s += ch;
        
        if(s == "aya" && !say[0])
        {
            s = "";
            say[0] = true;
            say[1] = false;
            say[2] = false;
            say[3] = false;
        }
        else if(s == "ye" && !say[1])
        {
            s = "";
            say[0] = false;
            say[1] = true;
            say[2] = false;
            say[3] = false;
        }
        else if( s == "woo" && !say[2])
        {
            s = "";
            say[0] = false;
            say[1] = false;
            say[2] = true;
            say[3] = false;
        }
        else if(s == "ma" && !say[3])
        {
            s = "";
            say[0] = false;
            say[1] = false;
            say[2] = false;
            say[3] = true;
        }
        else if(s == "aya" && say[0])
        {
            return false;
        }
        else if(s == "ye" && say[1])
        {
            return false;
        }
        else if(s == "woo" && say[2])
        {
            return false;
        }
        else if(s == "ma" && say[3])
        {
            return false;
        }
    }
    
    if(s.size() == 0)
        return true;
    else
        return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string str : babbling)
    {
        if(isBab(str))
            answer++;
    }
    
    return answer;
}