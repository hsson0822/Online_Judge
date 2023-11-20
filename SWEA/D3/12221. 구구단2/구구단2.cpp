#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int front;
        int back;
        
        cin >> front >> back;
        
        int result = front * back;
        if(front > 9 || back > 9)
            result = -1;
        
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}