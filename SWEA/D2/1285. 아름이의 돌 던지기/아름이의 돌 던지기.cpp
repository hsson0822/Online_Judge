#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int person;
        cin >> person;
        
        vector<int> vec;
        
        for(int i = 0 ; i < person ; ++i)
        {
            int n;
            cin >> n;
            n = abs(n);
            vec.push_back(n);
        }
        
        sort(vec.begin(), vec.end());
        int num = vec[0];
        int cnt = 0;
        
        for(int n : vec)
        {
            if(num == n)
                cnt++;
            else
                break;
        }
        
		cout << "#" << test_case << " " << num << " " << cnt << "\n";
	}
	return 0;
}