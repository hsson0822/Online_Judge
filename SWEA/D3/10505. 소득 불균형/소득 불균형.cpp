#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int peopleCount;
        cin >> peopleCount;
        
        vector<int> vec;
        
        int sum{};
        for(int i = 0 ; i < peopleCount ; ++i)
        {
            int n;
            cin >> n;
            vec.push_back(n);
            sum += n;
        }
        
        double avg = (double)sum / peopleCount;
        
        int cnt{};
        for(int n : vec)
        {
            if(n <= avg)
                ++cnt;
        }
cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}