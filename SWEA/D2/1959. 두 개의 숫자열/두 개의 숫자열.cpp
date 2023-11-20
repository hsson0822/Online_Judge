#include<iostream>
#include<deque>
#include<climits>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ACount;
        int BCount;
        
        cin >> ACount >> BCount;
        
        deque<int> A;
        deque<int> B;
        
        for(int i = 0 ; i < ACount ; ++i)
        {
            int n;
            cin>> n;
            A.push_back(n);
        }
        
        for(int i = 0 ; i < BCount ; ++i)
        {
            int n;
            cin>> n;
            B.push_back(n);
        }
        
        int max = INT_MIN;
        if(ACount > BCount)
		{
            for(int i = 0 ; i <= ACount - BCount ; ++i)
            {
                int sum{};
                for(int j = 0 ; j < BCount ; ++j)
                    sum += A[j] * B[j];
                if(max < sum)
                    max = sum;
                
                A.pop_front();
            }
        }
        else
        {
            for(int i = 0 ; i <= BCount - ACount ; ++i)
            {
                int sum{};
                for(int j = 0 ; j < ACount ; ++j)
                    sum += A[j] * B[j];
                if(max < sum)
                    max = sum;
                
                B.pop_front();
            }
        }
        
        cout << "#" << test_case << " " << max << "\n";
	}
	return 0;
}