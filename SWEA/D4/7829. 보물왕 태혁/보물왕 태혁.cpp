#include<iostream>
#include<set>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int count;
		cin >> count;

		set<int> nums;
		for (int i = 0; i < count; ++i)
		{
			int n;
			cin >> n;
			nums.insert(n);
		}
		

		cout << "#" << test_case << " " << *nums.begin() * *nums.rbegin() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
