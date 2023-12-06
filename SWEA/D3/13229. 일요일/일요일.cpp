#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    vector<string> days {"SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string day;
        cin >> day;
        
        auto it = find(days.begin(), days.end(), day);
        
         cout << "#" << test_case << " " << distance(days.begin(),it) +1 << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}