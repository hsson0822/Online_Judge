#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
	int test_case;
	int T;

	cin>>T;

    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int month1;
        int day1;
        int month2;
        int day2;
        
        cin >> month1 >> day1 >> month2 >> day2;
        
        int days1{};
        for(int i = 0 ; i < month1 -1 ; ++i)
            days1 += days[i];
        days1 += day1;
        
        int days2{};
        for(int i = 0 ; i < month2 -1 ; ++i)
            days2 += days[i];
        days2 += day2;
        
        cout << "#" << test_case << " " << days2 - days1 +1 << "\n";

	}
	return 0;
}