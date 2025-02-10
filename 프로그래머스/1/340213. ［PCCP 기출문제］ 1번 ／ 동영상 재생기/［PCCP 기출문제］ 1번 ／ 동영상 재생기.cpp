#include <string>
#include <vector>

using namespace std;

int video;
int now;
int opStart;
int opEnd;

int stringToSec(string str)
{
    string min = str.substr(0,2);
    string sec = str.substr(3,2);
    
    return (stoi(min) * 60 + stoi(sec));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    video = stringToSec(video_len);
    now = stringToSec(pos);
    opStart = stringToSec(op_start);
    opEnd = stringToSec(op_end);
    
    if(now >= opStart && now <= opEnd)
        now = opEnd;
    
    for(string c : commands)
    {
        if(c == "prev")
        {
            now -=10;
            
            if(now < 0)
                now = 0;
        }
        else if(c == "next")
        {
            now += 10;
            
            if(now >= video)
                now = video;
        }
        
        if(now >= opStart && now <= opEnd)
            now = opEnd;
    }
    
    int min = now / 60;
    now %= 60;
    
    string m = to_string(min);
    if(min < 10)
        m = '0'+m;
    
    string s = to_string(now);
    if(now < 10)
        s = '0'+s;
    
    answer += m + ":" + s;
    
    return answer;
}