#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
    
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
        
        string str;
        cin >> str;
        
        string yearStr{str.begin(), str.begin() + 4};
        string monthStr{str.begin() + 4, str.begin() + 6};
        string dayStr{str.begin() + 6 , str.end()};
        
        int year = stoi(yearStr);
        int month = stoi(monthStr);
        int day = stoi(dayStr);
        
        if(month < 1 || month > 12)
        {
            cout << -1 << "\n";    
            continue;
        }
        
        if(day < 1 || day > days[month-1])
        {
            cout << -1 << "\n";
            
            continue;
        }
        
        cout << yearStr << "/" << monthStr << "/" << dayStr << "\n";
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}