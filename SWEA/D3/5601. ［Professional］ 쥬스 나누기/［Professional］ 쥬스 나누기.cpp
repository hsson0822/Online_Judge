#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int people;
        cin >> people;
        
        cout << "#" << test_case << " ";
        for(int i = 0 ; i < people ; ++i)
        {
            cout << "1/" << people << " ";
        }
        cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}