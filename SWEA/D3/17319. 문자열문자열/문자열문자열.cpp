#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int size;
        cin >> size;
        
        string str;
        string a;
        string b;
        cin >> str;
        
        for(int i = 0 ; i < str.size(); ++i)
        {
            if(i < str.size()/2)
                a += str[i];
            else
                b += str[i];
        }
        
        string answer;
        if(a == b)
            answer = "Yes";
        else
            answer = "No";
        
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}