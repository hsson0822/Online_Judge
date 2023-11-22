#include<iostream>
#include<map>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
    {
		map<char, int> alpha;
        
        string str;
        cin >> str;
        
        for(char ch : str)
            alpha[ch]++;
        
        bool flag = true;
        
        if(alpha.size() != 2)
            flag = false;
        
        if(flag)
        {
        	for(auto m : alpha)
        	{
            	if(m.second != 2)
                {
                 	flag = false;
                    break;
                }
        	}
        }
        cout << "#" << test_case << " ";
        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}