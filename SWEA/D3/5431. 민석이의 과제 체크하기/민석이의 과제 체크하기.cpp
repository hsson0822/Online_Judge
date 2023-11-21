#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int studentCount;
        cin >> studentCount;
        
        int submitCount;
        cin >> submitCount;
        
        vector<int> submitList;
        vector<int> noSubmitList;
        
        for(int i = 0 ; i < submitCount; ++i)
        {
            int n;
            cin>> n;
            submitList.push_back(n);
        }
        
        for(int i = 1; i <= studentCount; ++i)
        {
            auto it = find(submitList.begin(), submitList.end(), i);
            if(it == submitList.end())
                noSubmitList.push_back(i);
        }
        
        cout << "#" << test_case << " ";
        
        for(int n : noSubmitList)
            cout << n << " ";
        cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}