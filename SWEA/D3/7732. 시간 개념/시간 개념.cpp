#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string before;
		cin >> before;

		string after;
		cin >> after;

		istringstream ss{ before };
		string s;
		vector<int> bef;

		while (getline(ss, s, ':'))
		{
			int n = stoi(s);
			bef.push_back(n);
		}

		istringstream sss{ after };
		vector<int> aft;

		while (getline(sss, s, ':'))
		{
			int n = stoi(s);
			aft.push_back(n);
		}

		int hour;
		int min;
		int sec;

		if (bef[0] > aft[0])
		{
			aft[0] += 24;
		}
		else if (bef[0] == aft[0])
		{
			if(bef[1] > aft[1])
				aft[0] += 24;
			else if(bef[1] == aft[1])
			{
				if(bef[2] > bef[2])
					aft[0] += 24;
			}

		}
		
		int b = bef[0] * 60 * 60 + bef[1] * 60 + bef[2];
		int a = aft[0] * 60 * 60 + aft[1] * 60 + aft[2];

		a -= b;

		hour = a / 3600;
		a %= 3600;
		min = a / 60;
		a %= 60;
		sec = a;

		if (sec > 60)
		{
			min += sec / 60;
			sec %= 60;
		}

		if (min > 60)
		{
			hour += min / 60;
			min %= 60;
		}

		if (hour >= 24)
			hour %= 24;

		if (hour < 0)
			hour += 24;

		string answer;
		if (hour < 10)
			answer += '0';
		answer += to_string(hour) + ":";
		
		if (min < 10)
			answer += '0';
		answer += to_string(min) + ":";

		if (sec < 10)
			answer += '0';
		answer += to_string(sec);

		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}