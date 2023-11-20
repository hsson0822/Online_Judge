#include<iostream>
#include<set>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin>>n;
        string str = to_string(n);
        
        set<int> s;
        for(char ch : str)
        {
            int k = ch -'0';
            s.insert(k);
        }
        cout << "#" << test_case << " " << s.size() << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}