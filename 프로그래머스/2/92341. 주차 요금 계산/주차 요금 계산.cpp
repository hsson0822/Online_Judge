#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> time;
	map<string, int> parking;
	map<string, int> money;
    vector<int> answer;
    

	for (string str : records)
	{
		istringstream ss{ str };
		vector<string> v;
		string s;

		while(getline(ss, s, ' '))
		{
			v.push_back(s);
		}

		string hourS;
		hourS += v[0][0];
		hourS += v[0][1];
		int hour = stoi(hourS);

		string minS;
		minS += v[0][3];
		minS += v[0][4];
		int min = stoi(minS);
		min += hour * 60;

		if (auto iter = parking.find(v[1]); iter != parking.end())
		{
			int diff = min - (*iter).second;
			
			time[v[1]] += diff;
			parking.erase(iter);
		}
		else
		{
			parking[v[1]] = min;
		}
	}

	for (auto m : parking)
	{
		int max = 23 * 60 + 59;
		int diff = max - m.second;
		time[m.first] += diff;
	}

	for (auto m : time)
	{
		int fee = fees[1];

		if (m.second > fees[0])
		{
			m.second -= fees[0];
			int extra = ceil((double)m.second / fees[2]);
			extra *= fees[3];
			fee += extra;

		}
		money[m.first] += fee;
        answer.push_back(fee);
	}

    return answer;
}