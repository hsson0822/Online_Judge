#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;

        sort(str.begin(), str.end());

        while (true)
        {
            auto iter = adjacent_find(str.begin(), str.end());
            if (iter != str.end())
                str.erase(iter, iter + 2);
            else
                break;
        }

        if (str.size() == 0)
            str = "Good";

        cout << "#" << test_case << " " << str << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}