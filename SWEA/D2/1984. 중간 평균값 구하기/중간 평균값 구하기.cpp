#include<iostream>
#include<climits>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int sum{};
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0 ; i < 10 ; ++i)
        {
            int n;
            cin >> n;
            sum+=n;
            
            if(n > max) max = n;
            if(n < min) min = n;
        }
        sum -= max;
        sum -= min;

		cout << "#" << test_case << " " << round((double)sum/8) << "\n";
	}
	return 0;
}