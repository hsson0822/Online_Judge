#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string baseStr;
		cin >> baseStr;
        
        string reverseStr = baseStr;
        reverse(reverseStr.begin(), reverseStr.end());
        
        bool isSame = false;
        if(baseStr == reverseStr)
            isSame = true;
        
		cout << "#" << test_case << " " << isSame << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}