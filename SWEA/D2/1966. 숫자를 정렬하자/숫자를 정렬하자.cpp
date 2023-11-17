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
        int numCount;
        cin >> numCount;
        multiset<int> nums;
        for(int i = 0 ; i < numCount ; ++i)
        {
            int n;
            cin >> n;
            nums.insert(n);
        }
        
		cout << "#" << test_case << " ";
        for(int n : nums)
            cout << n << " ";
        cout << "\n";
    }
	return 0;
}