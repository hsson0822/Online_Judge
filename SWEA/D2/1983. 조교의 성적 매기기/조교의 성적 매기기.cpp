#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	vector<string> grade {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int studentSize;
        int want;
        cin >> studentSize >> want;
        
        unordered_map<int, pair<double, string>> student;
        
        for(int i = 1 ; i <= studentSize ; ++i)
        {
            double a;
            double b;
            double c;
            cin >> a >> b >> c;
            double sum = a*0.35 + b*0.45 + c*0.20;
            
            student[i] = make_pair(sum, "");
        }
        
        vector<pair<int, pair<double,string>>> vec{student.begin(), student.end()};        
        sort(vec.begin(), vec.end(), [](auto& a, auto& b)
             {
                 return a.second.first > b.second.first;
             });
        
        cout << "#" << test_case << " ";
        for(int i = 0 ; i < vec.size(); ++i)
        {
            if(vec[i].first == want)
            {
                cout << grade[i/(studentSize/10)] << "\n";
                break;
            }
            
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}