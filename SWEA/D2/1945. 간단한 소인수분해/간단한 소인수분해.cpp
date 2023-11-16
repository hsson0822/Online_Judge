#include<iostream>
#include<map>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        long num;
        cin >> num;
        
        map<int, int> numCount;
    	numCount[2] = 0;
    	numCount[3] = 0;
    	numCount[5] = 0;
    	numCount[7] = 0;
    	numCount[11] = 0;
        
        while(num != 1)
        {
            if(num % 2 ==0)
            {
                numCount[2]++;
            	num /=2;
            }
            else if (num % 3 == 0)
            {
                numCount[3]++;
                num /=3;
            }
            else if (num % 5 == 0)
            {
                numCount[5]++;
                num /=5;
            }
            else if (num % 7 == 0)
            {
                numCount[7]++;
                num /=7;
            }
            else if (num % 11 == 0)
            {
                numCount[11]++;
                num /=11;
            }
        }
		
        cout << "#" << test_case << " ";
        
        for(auto m : numCount)
            cout << m.second << " ";
        cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}