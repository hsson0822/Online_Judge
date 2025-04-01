#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> alpha;
vector<int> answer;

string checkAlpha(string s, string msg, int& i, int& num)
{
	if (alpha[s] != 0 && i != msg.size() - 1)
	{
		string temp = s + msg[i + 1];

		if (alpha[temp] == 0)
		{
			alpha[temp] = num++;
			answer.push_back(alpha[s]);
			return {};
		}
		else
		{
			return checkAlpha(temp, msg, ++i, num);
		}
	}
	else
	{
		answer.push_back(alpha[s]);
		return {};
	}
	return {};
}

vector<int> solution(string msg) {

    char al = 'A';  
    int num = 1;
    for(; num <= 26 ; ++num)
    {
        string s = {al};
        alpha[s] = num;
        ++al;
    }
    
    string s{};
    for(int i = 0 ; i < msg.size() ; ++i)
    {
        s += msg[i];
        s = checkAlpha(s, msg, i, num);
    }
    
    return answer;
}