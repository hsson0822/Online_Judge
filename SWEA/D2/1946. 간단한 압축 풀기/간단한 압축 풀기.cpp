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
		int alphaSize;
        cin >> alphaSize;
        
        vector<char> alpha;
        
        for(int i = 0 ; i < alphaSize; ++i)
        {
            char al;
            int size;
            cin >> al >> size;
            
            for(int j = 0 ; j < size ; ++j)
                alpha.push_back(al);
        }
        
        cout << "#" << test_case << "\n";
        
        string str;
        for(int i = 0 ; i < alpha.size() ; ++i)
        {
            str += alpha[i];
            if(str.size() == 10)
            {
                cout <<str << "\n";
                str ="";
            }
        }
        cout <<str << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}