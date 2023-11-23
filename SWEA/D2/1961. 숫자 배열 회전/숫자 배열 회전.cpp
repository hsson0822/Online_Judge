#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> base;
        vector<vector<int>> turn90;
		vector<vector<int>> turn180;
        vector<vector<int>> turn270;
        
        int len;
        cin >> len;
        
        for(int i = 0 ; i < len ; ++i)
        {
            vector<int> vec;
            for(int j = 0 ; j < len ; ++j)
            {
                int n;
                cin >>n;
                vec.push_back(n);
            }
            base.push_back(vec);
            turn90.push_back(vec);
            turn180.push_back(vec);
            turn270.push_back(vec);
        }
        
        cout << "#" << test_case <<"\n";
        for(int i = 0 ; i < len; ++i)
            for(int j = 0 ; j < len ; ++j)
                turn90[i][j] = base[len - j -1][i];

        for(int i = 0 ; i < len; ++i)
            for(int j = 0 ; j < len ; ++j)
                turn180[i][j] = turn90[len - j -1][i];
        
        for(int i = 0 ; i < len; ++i)
            for(int j = 0 ; j < len ; ++j)
                turn270[i][j] = turn180[len - j -1][i];
        
        for(int i = 0 ; i < len; ++i)
        {
            for(int j = 0 ; j < len ; ++j)
                cout << turn90[i][j];
            cout << " ";
            
            for(int j = 0 ; j < len ; ++j)
                cout << turn180[i][j];
            cout << " ";
            
            for(int j = 0 ; j < len ; ++j)
                cout << turn270[i][j];
            cout << "\n";
        }
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}