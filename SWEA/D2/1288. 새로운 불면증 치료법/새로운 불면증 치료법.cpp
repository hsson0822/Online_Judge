#include<iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		set<int> numBox;
        int n;
        cin >> n;
        
        int num;
        int i = 1;
        while(numBox.size() != 10)
        {
            num = i * n;
            string str = to_string(num);
            for(char ch : str)
                numBox.insert(ch-'0');
            ++i;
        }
		
		cout <<  "#" << test_case << " " << num << "\n";
	}
	return 0;
}