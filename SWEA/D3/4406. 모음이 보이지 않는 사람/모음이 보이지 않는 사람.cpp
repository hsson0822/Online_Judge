#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string s;
        cin >> s;
        
        string newStr;
        for(char ch : s)
        {
           if(ch != 'a' && ch != 'e' && ch != 'i'&& ch != 'o' && ch != 'u') 
            	newStr += ch;
        }
        
        cout << "#" << test_case << " " << newStr << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}