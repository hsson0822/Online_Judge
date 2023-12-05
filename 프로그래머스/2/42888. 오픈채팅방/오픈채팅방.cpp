#include <string>
#include <vector>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> id;
	vector<pair<string, string>> log;

	for (string str : record)
	{
		istringstream ss{ str };
		string s;
		vector<string> v;

		while (getline(ss, s, ' '))
			v.push_back(s);

		if (v[0] == "Enter")
		{
			id[v[1]] = v[2];
			log.push_back(make_pair(v[1], v[0]));
		}
		else if (v[0] == "Leave")
		{
			log.push_back(make_pair(v[1], v[0]));
		}
		else
			id[v[1]] = v[2];
	}

	for (auto m : log)
	{
		string str = id[m.first] + "님이 ";

		if (m.second == "Enter")
			str += "들어왔습니다.";
		else
			str += "나갔습니다.";

		answer.push_back(str);
	}
    
    return answer;
}